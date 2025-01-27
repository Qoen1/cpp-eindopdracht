//
// Created by koenv on 30/10/2024.
//

#include "LookInputHandler.hpp"

#include <iostream>

#include "../commands/LookAtEnemyCommand.hpp"
#include "../commands/LookAtItemCommand.hpp"
#include "../commands/LookAtPlayerCommand.hpp"
#include "../commands/LookInRoomCommand.hpp"

namespace frontend {
    static const std::string TARGET_SELF = "self";
    void LookInputHandler::Handle(const std::vector<std::string> &arguments) const {
        if(arguments.size() == 0) {
            LookInRoomCommand(*player_.currentLocation, output_).Execute();
            return;
        }
        if(arguments[0] == TARGET_SELF) {
            LookAtPlayerCommand(player_, output_).Execute();
            return;
        }
        std::string entity_name;
        for (auto i = 0; i < arguments.size(); ++i) {
            entity_name += arguments[i];
            if (i != arguments.size() - 1) {
                entity_name += " ";
            }
        }
        auto* item = player_.currentLocation->GetItemByName(entity_name.c_str());
        if(item == nullptr) item = player_.GetItemByName(arguments[0]);
        if(item != nullptr) {
            LookAtItemCommand(*item, output_).Execute();
            return;
        }
        auto* enemy = player_.currentLocation->GetEnemyByName(entity_name.c_str());
        if(enemy != nullptr) {
            LookAtEnemyCommand(*enemy, player_, output_).Execute();
        }
    }
} // frontend