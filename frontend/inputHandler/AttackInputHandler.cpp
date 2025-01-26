//
// Created by koenv on 25/01/2025.
//

#include "AttackInputHandler.hpp"
#include "../player/Player.hpp"
#include <iostream>

#include "../commands/AttackCommand.hpp"

namespace frontend {
    AttackInputHandler::AttackInputHandler(const std::string &inputCommand, Player &player,
                                           std::shared_ptr<frontend::ICommand> move_enemies_command): BaseInputHandler(
        inputCommand), player_(player), move_enemies_command(move_enemies_command) {
    }

    void AttackInputHandler::Handle(const std::vector<std::string> &arguments) const {
        if(arguments.size() == 0) {
            std::cout << "Attack what?" << std::endl;
            return;
        }
        std::string entity_name;
        for (auto i = 0; i < arguments.size(); ++i) {
            entity_name += arguments[i];
            if (i != arguments.size() - 1) {
                entity_name += " ";
            }
        }
        auto& enemy = *player_.currentLocation->GetEnemyByName(entity_name.c_str());
        if(&enemy == nullptr) {
            std::cout << "There is no enemy with the name " << entity_name << std::endl;
            return;
        }

        AttackCommand(player_, enemy).Execute();

        if (enemy.GetHealth() <= 0) {
            std::cout << "You have defeated the enemy!" << std::endl;
            auto items = enemy.TransferItems();
            for (auto i = 0; i < items.size(); ++i) {
                player_.currentLocation->AddVisibleItem(items.pop(i));
            }
        }

        move_enemies_command->Execute();
    }
} // frontend