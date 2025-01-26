//
// Created by koenv on 25/01/2025.
//

#include "WearInputHandler.hpp"

#include <iostream>

#include "../commands/ICommand.hpp"
#include "../player/Player.hpp"

namespace frontend {
    WearInputHandler::WearInputHandler(const std::string &inputCommand, Player &player, std::shared_ptr<ICommand> move_enemies_command):
    BaseInputHandler(inputCommand), player_(player), move_enemies_command_(move_enemies_command) {}

    void WearInputHandler::Handle(const std::vector<std::string> &arguments) const {
        std::string item_name;
        for (auto i = 0; i < arguments.size(); ++i) {
            item_name += arguments[i];
            if (i != arguments.size() - 1) {
                item_name += " ";
            }
        }

        bool is_armor {dynamic_cast<backend::Armor*>(player_.GetItemByName(item_name)) == nullptr};


        auto succeeded = player_.UseItemFromInventory(item_name);
        if (!succeeded) {
            std::cout << "You don't have that item in your inventory, or it is not a weapon or armor" << std::endl;
        }else {
            std::cout << "You have equipped the " << item_name << std::endl;
        }

        if (succeeded && is_armor) {
            move_enemies_command_->Execute();
        }
    }
} // frontend