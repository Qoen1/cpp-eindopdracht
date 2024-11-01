//
// Created by koenv on 01/11/2024.
//

#include "MoveInputHandler.hpp"

#include "../commands/MoveCommand.hpp"

namespace frontend {
    MoveInputHandler::MoveInputHandler(const std::string& command, Player &player) : player_(player), BaseInputHandler(command) {
    }

    void MoveInputHandler::Handle(const std::vector<std::string> &arguments) const {
        MoveCommand(GetDirectionFromString(arguments[0]), player_).Execute();
    }
} // frontend