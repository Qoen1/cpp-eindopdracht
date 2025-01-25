//
// Created by koenv on 25/01/2025.
//

#include "WearInputHandler.hpp"

#include <iostream>

#include "../player/Player.hpp"

namespace frontend {
    WearInputHandler::WearInputHandler(const std::string &inputCommand, Player &player):
    BaseInputHandler(inputCommand), player_(player) {}

    void WearInputHandler::Handle(const std::vector<std::string> &arguments) const {
        std::string item_name;
        for (auto i = 0; i < arguments.size(); ++i) {
            item_name += arguments[i];
            if (i != arguments.size() - 1) {
                item_name += " ";
            }
        }

        auto succeeded = player_.UseItemFromInventory(item_name);
        if (!succeeded) {
            std::cout << "You don't have that item in your inventory, or it is not a weapon or armor" << std::endl;
        }else {
            std::cout << "You have equipped the " << item_name << std::endl;
        }
    }
} // frontend