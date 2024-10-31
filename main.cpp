#include <iostream>

#include "backend/location/Location.hpp"
#include "backend/objects/Weapon.hpp"
#include "frontend/commands/LookAtItemCommand.hpp"
#include "frontend/commands/LookAtPlayerCommand.hpp"
#include "frontend/commands/LookInRoomCommand.hpp"
#include "frontend/configReader/RandomMapGenerator.hpp"
#include "frontend/inputHandler/LookInputHandler.hpp"


int main()
{
    auto generator = RandomMapGenerator();
    auto locations = std::make_unique<std::vector<backend::Location*>>(*generator.Generate());
    auto* ree {new backend::Weapon(*new helpers::TypoTrap("odin's sword"), *new helpers::TypoTrap("a mighty sword that creates sparkles"))};
    auto* lego {new backend::Weapon(*new helpers::TypoTrap("lego set"), *new helpers::TypoTrap("if anyone steps on this, it hurts a lot!"))};
    auto* enemy {new backend::Enemy(new helpers::TypoTrap("goblin"), new helpers::TypoTrap("a small green creature"), 10)};
    auto* player {new frontend::Player(*locations->at(0))};
    player->AddItemToInventory(new backend::Weapon(*new helpers::TypoTrap("sword"), *new helpers::TypoTrap("a mighty sword")));
    player->AddItemToInventory(new backend::Armor(*new helpers::TypoTrap("shield"), *new helpers::TypoTrap("a shield that protects you")));
    player->UseWeaponFromInventory("sword");
    enemy->AddItem(lego);
    locations->at(0)->AddEnemy(enemy);

    locations->at(0)->AddVisibleItem(ree);

    std::cout << "testing look input handler:" << std::endl;
    frontend::BaseInputHandler* inputHandler = new frontend::LookInputHandler("look",*player);
    std::cout << "=====" << std::endl;
    inputHandler->Handle("look", {"odin's sword"});
    std::cout << "=====" << std::endl;
    inputHandler->Handle("look", {});
    std::cout << "=====" << std::endl;
    inputHandler->Handle("look", {"self"});
    std::cout << "=====" << std::endl;
    inputHandler->Handle("look", {"goblin"});
    std::cout << "=====" << std::endl;



    return 0;
}
