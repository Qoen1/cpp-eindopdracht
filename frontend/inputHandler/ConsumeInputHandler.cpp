//
// Created by koenv on 26/01/2025.
//

#include "ConsumeInputHandler.hpp"

#include <iostream>

#include "../commands/ConsumeItemCommand.hpp"

namespace frontend {
    ConsumeInputHandler::ConsumeInputHandler(const std::string &inputCommand, Player &player, std::ostream &output)
            : BaseInputHandler(inputCommand),
              player_(player), output_(output) {
    }

    void ConsumeInputHandler::Handle(const std::vector<std::string> &arguments) const {
        if (arguments.size() < 1) {
            output_ << "Invalid number of arguments" << std::endl;
            return;
        }

        std::string item_name;
        for (auto i = 0; i < arguments.size(); ++i) {
            item_name += arguments[i];
            if (i != arguments.size() - 1) {
                item_name += " ";
            }
        }

        ConsumeItemCommand(player_, item_name, output_).Execute();
    }
} // frontend