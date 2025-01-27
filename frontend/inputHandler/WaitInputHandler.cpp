//
// Created by koenv on 26/01/2025.
//

#include "WaitInputHandler.hpp"

#include "../commands/ICommand.hpp"

namespace frontend {
    WaitInputHandler::WaitInputHandler(const std::string &inputCommand,
                                       ICommand &move_enemies_command, std::ostream& output): BaseInputHandler(
        inputCommand), move_enemies_command(move_enemies_command), output_(output) {
    }

    void WaitInputHandler::Handle(const std::vector<std::string> &arguments) const {
        move_enemies_command.Execute();
    }
} // frontend