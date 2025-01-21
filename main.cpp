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


int main()
{
    helpers::DynamicDoodad<helpers::BigBrainPointer<helpers::TypoTrap>> test {};

    test.push_back(helpers::BigBrainPointer(new helpers::TypoTrap{"je moeder"}));
    test.push_back(helpers::BigBrainPointer(new helpers::TypoTrap{"is een"}));
    test.push_back(helpers::BigBrainPointer(new helpers::TypoTrap{"beetje gay"}));

    helpers::DynamicDoodad<helpers::TypoTrap*> non_owning_test {};
    non_owning_test.push_back(new helpers::TypoTrap{"je moeder"});
    auto generator = RandomMapGenerator();
    auto locations = std::make_unique<std::vector<backend::Location*>>(*generator.Generate());
    auto ree = helpers::BigBrainPointer<backend::Item>{new backend::Weapon(*new helpers::TypoTrap("odin's sword"), *new helpers::TypoTrap("a mighty sword that creates sparkles"))};
    auto lego = helpers::BigBrainPointer<backend::Item>(new backend::Weapon(*new helpers::TypoTrap("lego set"), *new helpers::TypoTrap("if anyone steps on this, it hurts a lot!")));
    auto enemy = helpers::BigBrainPointer(new backend::Enemy(new helpers::TypoTrap("goblin"), new helpers::TypoTrap("a small green creature"), 10));
    auto player = helpers::BigBrainPointer{new frontend::Player(locations->at(0))};
    player->AddItemToInventory(new backend::Weapon(*new helpers::TypoTrap("sword"), *new helpers::TypoTrap("a mighty sword")));
    player->AddItemToInventory(new backend::Armor(*new helpers::TypoTrap("shield"), *new helpers::TypoTrap("a shield that protects you")));
    player->UseWeaponFromInventory("sword");

    player->currentLocation = locations->at(0);
    enemy->AddItem(static_cast<helpers::BigBrainPointer<backend::Item>&&>(lego));
    locations->at(0)->AddEnemy(static_cast<helpers::BigBrainPointer<backend::Enemy>&&>(enemy));

    locations->at(0)->AddVisibleItem(static_cast<helpers::BigBrainPointer<backend::Item>&&>(ree));
    // locations->at(0)->AddHiddenItem(static_cast<helpers::BigBrainPointer<backend::Item>&&>(lego));
    auto location = locations->at(0);
    location->AddNeighbor(SOUTH, locations->at(1));


    std::vector<frontend::BaseInputHandler*> inputHandlers = {
        new frontend::LookInputHandler("look",*player),
        new frontend::SearchInputHandler("search", *player),
        new frontend::MoveInputHandler("move", *player)
    };
    frontend::BaseInputHandler* inputHandler = nullptr;
    for(auto handler : inputHandlers) {
        if(inputHandler != nullptr) {
            handler->SetNextHandler(*inputHandler);
        }
        inputHandler = handler;
    }

    std::cout << "testing look input handler:" << std::endl;
    std::cout << "=====" << std::endl;
    inputHandler->Handle("look", {"odin's sword"});
    std::cout << "=====" << std::endl;
    inputHandler->Handle("look", {});
    std::cout << "=====" << std::endl;
    inputHandler->Handle("look", {"self"});
    std::cout << "=====" << std::endl;
    inputHandler->Handle("look", {"goblin"});
    std::cout << "=====" << std::endl;

    std::cout << "testing search input handler:" << std::endl;
    std::cout << "=====" << std::endl;
    inputHandler->Handle("search", {});
    inputHandler->Handle("look", {});
    std::cout << "=====" << std::endl;

    std::cout << "testing move input handler:" << std::endl;
    std::cout << "=====" << std::endl;
    inputHandler->Handle("move", {"south"});
    std::cout << "=====" << std::endl;
    inputHandler->Handle("look", {});
    std::cout << "=====" << std::endl;

    return 0;
}
