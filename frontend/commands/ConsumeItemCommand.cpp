//
// Created by koenv on 26/01/2025.
//

#include "ConsumeItemCommand.hpp"

#include "../../backend/objects/consumable/Consumable.hpp"
#include "../player/Player.hpp"

namespace frontend {
    ConsumeItemCommand::ConsumeItemCommand(Player &player, const std::string &item_name)
            : player_(player),
              item_name_(item_name) {
    }

    void ConsumeItemCommand::Execute() {
        auto* item = player_.GetItemByName(item_name_);
        if (dynamic_cast<backend::Consumable*>(item)) {
            dynamic_cast<backend::Consumable&>(*player_.PopItemByName(item_name_)).Consume(player_);
        }
    }
} // frontend