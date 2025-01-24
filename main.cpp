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
#include "frontend/inputHandler/InvalidInputHandler.hpp"
#include "frontend/inputHandler/QuitInputHandler.hpp"
#include "frontend/inputHandler/TakeInputHandler.hpp"

#define MAX_INPUT_LENGTH 100

bool playing {true};

int main()
{
    // auto generator = RandomMapGenerator();
    // auto locations = std::vector(generator.Generate());


    auto file_reader = FileMapGenerator("kasteelruine.xml", "kerkersendraken.db");
    auto locations = file_reader.Generate();

    auto player = std::make_unique<frontend::Player>(locations.at(0).get());

    player->currentLocation = locations.at(0).get();

    std::vector<frontend::BaseInputHandler*> inputHandlers = {
        new frontend::InvalidInputHandler(), //needs to be last because it always consumes the command.
        new frontend::LookInputHandler("look",*player),
        new frontend::SearchInputHandler("search", *player),
        new frontend::MoveInputHandler("move", *player),
        new frontend::TakeInputHandler("take", *player),
        new frontend::QuitInputHandler("quit", playing)
    };
    frontend::BaseInputHandler* inputHandler = nullptr;
    for(auto handler : inputHandlers) {
        if(inputHandler != nullptr) {
            handler->SetNextHandler(*inputHandler);
        }
        inputHandler = handler;
    }


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
    return 0;


    // helpers::OwningDynamicDoodad<backend::Location> locations;
    // locations.push_back(new backend::Location("Kasteelruine", "Een vervallen kasteelruine."));
    // locations.push_back(new backend::Location("Kerker", "Een donkere kerker."));
    // locations.push_back(new backend::Location("Grote zaal", "Een grote zaal met een troon."));
    //
    // helpers::OwningDynamicDoodad<backend::Item> items;
    // items.push_back(new backend::Weapon("Zwaard", "Een scherp zwaard."));
    // items.push_back(new backend::Weapon("Schild", "Een stevig schild."));
    // items.push_back(new backend::Weapon("Schild", "Een stevig schild."));
    // items.push_back(new backend::Weapon("Schild", "Een stevig schild."));
    // items.push_back(new backend::Weapon("Schild", "Een stevig schild."));
    //
    // locations.get(0).AddVisibleItem(items.pop(0));
    // locations.get(0).AddVisibleItem(helpers::BigBrainPointer<backend::Item>(new backend::Consumable({"GOOOOLD"}, {"heel veel centjes"})));


}
