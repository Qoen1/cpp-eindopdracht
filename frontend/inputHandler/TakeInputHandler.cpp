//
// Created by koenv on 24/01/2025.
//

#include "TakeInputHandler.hpp"
#include "../player/Player.hpp"
#include <iostream>

#include "../../backend/objects/Gold.hpp"

namespace frontend {
    void TakeInputHandler::Handle(const std::vector<std::string> &arguments) const {
        if (arguments.size() == 0) {
            output_ << "You need to specify what you want to take." << std::endl;
            return;
        }
        std::string item_name;
        for (auto i = 0; i < arguments.size(); ++i) {
            item_name += arguments[i];
            if (i != arguments.size() - 1) {
                item_name += " ";
            }
        }

        helpers::TypoTrap item = {item_name.c_str()};
        std::unique_ptr<backend::Item> itemPtr {player_.currentLocation->PopItemByName(item).pop()};
        if (itemPtr == nullptr) {
            output_ << "There is no " << item << " here." << std::endl;
            return;
        }
        player_.AddItemToInventory(std::move(itemPtr));
        output_ << "You took the " << item << "." << std::endl;
    }
} // frontend