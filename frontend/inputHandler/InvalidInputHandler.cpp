

#include "InvalidInputHandler.hpp"

#include <iostream>

namespace frontend {
    InvalidInputHandler::InvalidInputHandler(std::ostream& output): BaseInputHandler(""), output_(output) {}

    void InvalidInputHandler::Handle(const std::string& inputCommand, const std::vector<std::string>& arguments) const {
        output_ << "Invalid input command: " << inputCommand << " with parameters: ";
        for (const auto& argument : arguments) {
            output_ << argument << ", ";
        }
        output_ << std::endl;
    }

    void InvalidInputHandler::Handle(const std::vector<std::string>& arguments) const {}
} // frontend