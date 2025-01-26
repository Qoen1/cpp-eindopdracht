//
// Created by koenv on 26/01/2025.
//

#include "WaitInputHandler.hpp"

namespace frontend {
    WaitInputHandler::WaitInputHandler(const std::string &inputCommand): BaseInputHandler(inputCommand) {
    }

    void WaitInputHandler::Handle(const std::vector<std::string> &arguments) const {
        //TODO: enemy turn
    }
} // frontend