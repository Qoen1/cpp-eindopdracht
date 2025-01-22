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
            LookInRoomCommand(*player_.currentLocation).Execute();
            return;
        }
        if(arguments[0] == TARGET_SELF) {
            LookAtPlayerCommand(player_).Execute();
            return;
        }
        auto tempArg = helpers::TypoTrap(arguments[0].c_str());
        auto* item = player_.currentLocation->GetItemByName(tempArg);
        if(item == nullptr) item = player_.GetItemByName(arguments[0]);
        if(item != nullptr) {
            LookAtItemCommand(*item).Execute();
            return;
        }
        auto* enemy = player_.currentLocation->GetEnemyByName(tempArg);
        if(enemy != nullptr) {
            LookAtEnemyCommand(*enemy, player_).Execute();
        }
    }
} // frontend