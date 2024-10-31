//
// Created by koenv on 30/10/2024.
//

#include "BaseInputHandler.hpp"

namespace frontend {
    BaseInputHandler::BaseInputHandler(const std::string &inputCommand) {
        this->inputCommand = std::make_unique<const std::string>(inputCommand);
    }

    void BaseInputHandler::SetNextHandler(const BaseInputHandler& nextHandler) {
        this->nextHandler = std::unique_ptr<const BaseInputHandler>(&nextHandler);
    }

    void BaseInputHandler::Handle(const std::string& inputCommand, const std::vector<std::string>& arguments) const {
        if(*this->inputCommand != inputCommand) {
            nextHandler->Handle(inputCommand, arguments);
            return;
        }
        Handle(arguments);
    }
} // frontend