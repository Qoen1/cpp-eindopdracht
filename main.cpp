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

#include "frontend/database/Database.hpp"

#define MAX_INPUT_LENGTH 100

int main()
{
    // helpers::OwningDynamicDoodad<helpers::TypoTrap> owning_word_list;
    // // owning_word_list.push_back(helpers::BigBrainPointer(new helpers::TypoTrap("dit is een test")));
    // // owning_word_list.push_back(helpers::BigBrainPointer(new helpers::TypoTrap("dit is de tweede test")));
    // // owning_word_list.erase(1);
    // // owning_word_list.push_back(helpers::BigBrainPointer(new helpers::TypoTrap("dit is de derde test")));
    // // owning_word_list.push_back(helpers::BigBrainPointer(helpers::BigBrainPointer(new helpers::TypoTrap("dit is de vierde test"))));
    // for (unsigned int i = 0; i < 100; ++i) {
    //     owning_word_list.push_back(helpers::BigBrainPointer(new helpers::TypoTrap(std::to_string(i).c_str())));
    // }
    // for (unsigned int i = 0; i < owning_word_list.size(); ++i) {
    //     std::cout << owning_word_list.get(i).cstring() << std::endl;
    // }
    auto db = frontend::Database("kerkersendraken.db");
    auto all_locations = db.GetLocations();

    helpers::DynamicDoodad<helpers::BigBrainPointer<helpers::TypoTrap>> test {};

    test.push_back(helpers::BigBrainPointer(new helpers::TypoTrap{"je moeder"}));
    test.push_back(helpers::BigBrainPointer(new helpers::TypoTrap{"is een"}));
    test.push_back(helpers::BigBrainPointer(new helpers::TypoTrap{"beetje gay"}));

    helpers::DynamicDoodad<helpers::TypoTrap*> non_owning_test {};
    non_owning_test.push_back(new helpers::TypoTrap{"je moeder"});
    auto generator = RandomMapGenerator();
    auto locations = std::vector(generator.Generate());
    auto ree = helpers::BigBrainPointer<backend::Item>{new backend::Weapon(*new helpers::TypoTrap("odin's sword"), *new helpers::TypoTrap("a mighty sword that creates sparkles"))};
    auto lego = helpers::BigBrainPointer<backend::Item>(new backend::Weapon(*new helpers::TypoTrap("lego set"), *new helpers::TypoTrap("if anyone steps on this, it hurts a lot!")));
    auto enemy = helpers::BigBrainPointer(new backend::Enemy(new helpers::TypoTrap("goblin"), new helpers::TypoTrap("a small green creature"), 10));
    auto player = helpers::BigBrainPointer{new frontend::Player(locations.at(0).get())};
    player->AddItemToInventory(new backend::Weapon(*new helpers::TypoTrap("sword"), *new helpers::TypoTrap("a mighty sword")));
    player->AddItemToInventory(new backend::Armor(*new helpers::TypoTrap("shield"), *new helpers::TypoTrap("a shield that protects you")));
    player->UseWeaponFromInventory("sword");

    player->currentLocation = locations.at(0).get();
    enemy->AddItem(static_cast<helpers::BigBrainPointer<backend::Item>&&>(lego));
    locations.at(0)->AddEnemy(static_cast<helpers::BigBrainPointer<backend::Enemy>&&>(enemy));

    locations.at(0)->AddVisibleItem(static_cast<helpers::BigBrainPointer<backend::Item>&&>(ree));
    // locations->at(0)->AddHiddenItem(static_cast<helpers::BigBrainPointer<backend::Item>&&>(lego));
    auto& location = *locations.at(0);
    location.AddNeighbor(SOUTH, *locations.at(1));


    std::vector<frontend::BaseInputHandler*> inputHandlers = {
        new frontend::LookInputHandler("look",*player),
        new frontend::SearchInputHandler("search", *player),
        new frontend::MoveInputHandler("move", *player),
    };
    frontend::BaseInputHandler* inputHandler = nullptr;
    for(auto handler : inputHandlers) {
        if(inputHandler != nullptr) {
            handler->SetNextHandler(*inputHandler);
        }
        inputHandler = handler;
    }


    while (true) {
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

    return 0;
}
