//
// Created by koenv on 26/01/2025.
//

#include "ConsumeItemCommand.hpp"

#include <iostream>

#include "../../backend/objects/consumable/Consumable.hpp"
#include "../player/Player.hpp"

namespace frontend {
    ConsumeItemCommand::ConsumeItemCommand(Player &player, const std::string &item_name, std::ostream& output)
            : player_(player),
              item_name_(item_name),
              output_(output) {
    }

    void ConsumeItemCommand::Execute() {
        auto* item = player_.GetItemByName(item_name_);
        if (dynamic_cast<backend::Consumable*>(item)) {
            output_ << "you consume the " << item_name_ << std::endl;
            dynamic_cast<backend::Consumable&>(*player_.PopItemByName(item_name_)).Consume(player_);
        }else {
            output_ << "you can't consume that" << std::endl;
        }
    }
} // frontend