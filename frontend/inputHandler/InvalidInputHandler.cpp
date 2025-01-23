

#include "InvalidInputHandler.hpp"

#include <iostream>

namespace frontend {
    InvalidInputHandler::InvalidInputHandler(): BaseInputHandler("") {}

    void InvalidInputHandler::Handle(const std::string& inputCommand, const std::vector<std::string>& arguments) const {
        std::cerr << "Invalid input command: " << inputCommand << " with parameters: ";
        for (const auto& argument : arguments) {
            std::cerr << argument << ", ";
        }
        std::cerr << std::endl;
    }

    void InvalidInputHandler::Handle(const std::vector<std::string>& arguments) const {}
} // frontend