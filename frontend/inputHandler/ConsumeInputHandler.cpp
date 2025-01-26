//
// Created by koenv on 26/01/2025.
//

#include "ConsumeInputHandler.hpp"

#include <iostream>

#include "../commands/ConsumeItemCommand.hpp"

namespace frontend {
    ConsumeInputHandler::ConsumeInputHandler(const std::string &inputCommand, Player &player)
            : BaseInputHandler(inputCommand),
              player_(player) {
    }

    void ConsumeInputHandler::Handle(const std::vector<std::string> &arguments) const {
        if (arguments.size() < 1) {
            std::cout << "Invalid number of arguments" << std::endl;
            return;
        }

        std::string item_name;
        for (auto i = 0; i < arguments.size(); ++i) {
            item_name += arguments[i];
            if (i != arguments.size() - 1) {
                item_name += " ";
            }
        }

        ConsumeItemCommand(player_, item_name).Execute();
    }
} // frontend