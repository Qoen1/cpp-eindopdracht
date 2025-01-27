//
// Created by koenv on 31/10/2024.
//

#include "LookAtItemCommand.hpp"

#include <iostream>

namespace frontend {
    LookAtItemCommand::LookAtItemCommand(const backend::Item &item, std::ostream& output) : item_{item}, output_(output) {
    }

    void LookAtItemCommand::Execute() {
        output_ << item_.GetDescription().cstring() << std::endl;
    }
} // frontend