//
// Created by koenv on 01/11/2024.
//

#include "MoveInputHandler.hpp"

#include "../commands/MoveCommand.hpp"

namespace frontend {
    MoveInputHandler::MoveInputHandler(const std::string &command, Player &player,
                                       ICommand &move_enemies_command, std::ostream& output) : player_(player),
        BaseInputHandler(command), move_enemies_command_(move_enemies_command), output_(output) {
    }

    void MoveInputHandler::Handle(const std::vector<std::string> &arguments) const {
        try {
            MoveCommand(GetDirectionFromString(arguments[0]), player_).Execute();
            move_enemies_command_.Execute();
        }catch (std::invalid_argument& e) { /*swallow*/ }
    }
} // frontend