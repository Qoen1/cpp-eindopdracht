#include <iostream>

#include "helpers/BigBrainPointer.hpp"
#include "helpers/DynamicDoodad.hpp"
#include "helpers/TypoTrap.hpp"

#include "backend/location/Location.hpp"
#include "backend/objects/Weapon.hpp"
#include "frontend/commands/LookAtItemCommand.hpp"
#include "frontend/commands/LookAtPlayerCommand.hpp"
#include "frontend/commands/LookInRoomCommand.hpp"
#include "frontend/configReader/RandomMapGenerator.hpp"
#include "frontend/inputHandler/LookInputHandler.hpp"
#include "frontend/inputHandler/MoveInputHandler.hpp"
#include "frontend/inputHandler/SearchInputHandler.hpp"
#include <memory>
#include <vector>
#include <sqlite3.h>

#include "backend/objects/Consumable.hpp"
#include "backend/objects/Gold.hpp"
#include "frontend/configReader/FileMapGenerator.hpp"
#include "frontend/database/Database.hpp"
#include "frontend/inputHandler/AttackInputHandler.hpp"
#include "frontend/inputHandler/InvalidInputHandler.hpp"
#include "frontend/inputHandler/PlaceInputHandler.hpp"
#include "frontend/inputHandler/QuitInputHandler.hpp"
#include "frontend/inputHandler/TakeInputHandler.hpp"
#include "frontend/inputHandler/WearInputHandler.hpp"

#define MAX_INPUT_LENGTH 100

bool playing {true};

int main()
{
    // auto generator = RandomMapGenerator();
    // auto locations = std::vector(generator.Generate());


    auto file_reader = FileMapGenerator("kasteelruine.xml", "kerkersendraken.db");
    auto locations = file_reader.Generate();

    auto player = std::make_unique<frontend::Player>(locations.at(0).get());
    player->AddItemToInventory(std::make_unique<backend::Weapon>("wooden sword", "a wooden sword", 5));

    std::vector<frontend::BaseInputHandler*> inputHandlers = {
        new frontend::InvalidInputHandler(), //needs to be last because it always consumes the command.
        new frontend::LookInputHandler("look",*player),
        new frontend::SearchInputHandler("search", *player),
        new frontend::MoveInputHandler("move", *player),
        new frontend::TakeInputHandler("take", *player),
        new frontend::PlaceInputHandler("place", *player),
        new frontend::WearInputHandler("wear", *player),
        new frontend::AttackInputHandler("attack", *player),
        new frontend::QuitInputHandler("quit", playing)
    };
    frontend::BaseInputHandler* inputHandler = nullptr;
    for(auto handler : inputHandlers) {
        if(inputHandler != nullptr) {
            handler->SetNextHandler(*inputHandler);
        }
        inputHandler = handler;
    }


    frontend::LookInRoomCommand(*player->currentLocation).Execute();

    // ReSharper disable once CppDFALoopConditionNotUpdated
    while (playing) {
        char result[MAX_INPUT_LENGTH];
        std::cin.getline(result, MAX_INPUT_LENGTH);
        std::string line {result};
        std::vector<std::string> parts;

        auto space = line.find(' ');
        bool go_on {true};
        while (go_on) {
            parts.push_back(line.substr(0, space));
            line = line.substr(space + 1);
            go_on = space != std::string::npos;
            space = line.find(' ');

        }
        auto command = parts[0];
        parts.erase(parts.begin());
        inputHandler->Handle(command, parts);
    }
    for (auto i = 0; i < locations.size(); ++i) {
        locations[i] = nullptr;
    }

    delete inputHandler;
    return 0;





    // auto item_types = helpers::DynamicDoodad<backend::ItemTypeDTO>();
    // item_types.push_back({"name1", "description1", "type1", 1, 2, 3});
    //
    // auto items = helpers::DynamicDoodad<backend::Item>();
    // items.push_back(backend::Item(helpers::TypoTrap("name1"), helpers::TypoTrap("description1")));
    //
    // auto weapon = std::make_unique<backend::Weapon>("zwaard", "heel groot zwaard");
    // {
    //     auto weapons = helpers::DynamicDoodad<backend::Weapon*>();
    //     weapons.push_back(weapon.get());
    // }
    // std::cout << weapon->GetName() << std::endl;
}
