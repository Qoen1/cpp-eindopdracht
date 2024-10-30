//
// Created by koenv on 30/10/2024.
//

#include "LookInputHandler.hpp"

#include <iostream>

#include "../commands/LookInRoomCommand.hpp"

namespace frontend {
    static const std::string TARGET_SELF = "Self";
    void LookInputHandler::Handle(const std::vector<const std::string> &arguments) const {
        if(arguments.size() == 0) {
            LookInRoomCommand(player_.currentLocation).Execute();
            return;
        }
        if(arguments[0] == TARGET_SELF) {
            LookAtSelf();
            return;
        }
        auto* item = player_.currentLocation.GetItemByName(arguments[0]);
        if(item == nullptr) item = player_.GetItemByName(arguments[0]);
        if(item != nullptr) {
            std::cout << item->Description.cstring() << std::endl;
            return;
        }
        auto* enemy = player_.currentLocation.GetEnemyByName(arguments[0]);
        if(item != nullptr) {
            if(enemy->GetHealth() > 0) std::cout << enemy->description << std::endl;
            else {
                std::cout << "You see the remains of " << enemy->name << std::endl;
                for (int i = 0; i < enemy->GetItems().size(); ++i) {
                    player_.currentLocation.AddVisibleItem(enemy->GetItems()[i]);
                }
            }
            return;
        }
    }
} // frontend