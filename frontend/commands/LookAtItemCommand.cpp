//
// Created by koenv on 31/10/2024.
//

#include "LookAtItemCommand.hpp"

#include <iostream>

namespace frontend {
    LookAtItemCommand::LookAtItemCommand(const backend::Item &item) : item_{item} {
    }

    void LookAtItemCommand::Execute() {
        std::cout << item_.GetDescription().cstring() << std::endl;
    }
} // frontend