//
// Created by koenv on 26/01/2025.
//

#include "WaitInputHandler.hpp"

#include "../commands/ICommand.hpp"

namespace frontend {
    WaitInputHandler::WaitInputHandler(const std::string &inputCommand,
                                       std::shared_ptr<frontend::ICommand> move_enemies_command): BaseInputHandler(
        inputCommand), move_enemies_command(move_enemies_command) {
    }

    void WaitInputHandler::Handle(const std::vector<std::string> &arguments) const {
        move_enemies_command->Execute();
    }
} // frontend