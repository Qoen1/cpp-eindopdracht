//
// Created by koenv on 25/01/2025.
//

#include "PlaceInputHandler.hpp"
#include "../player/Player.hpp"
#include <iostream>

namespace frontend {
    void PlaceInputHandler::Handle(const std::vector<std::string> &arguments) const {
        if (arguments.size() < 1) {
            std::cout << "please provide the name of the item to place" << std::endl;
            return;
        }

        std::string item_name;
        for (auto i = 0; i < arguments.size(); ++i) {
            item_name += arguments[i];
            if (i != arguments.size() - 1) {
                item_name += " ";
            }
        }
        auto item = player_.PopItemByName(item_name);

        if (item == nullptr) {
            std::cout << "You do not have an item with the name " << item_name << std::endl;
            return;
        }

        player_.currentLocation->AddVisibleItem({item.release()});

        std::cout << "You placed the item " << item_name << std::endl;
    }
} // frontend