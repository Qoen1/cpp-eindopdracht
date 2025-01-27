//
// Created by koenv on 31/10/2024.
//

#include "LookAtEnemyCommand.hpp"

#include <iostream>

namespace frontend {
    LookAtEnemyCommand::LookAtEnemyCommand(backend::Enemy &enemy, Player& player, std::ostream& output) : enemy_{enemy}, player_(player), output_(output) {
    }

    void LookAtEnemyCommand::Execute() {
        if(enemy_.GetHealth() > 0) output_ << enemy_.GetDescription() << std::endl;
        else {
            output_ << "You see the remains of " << enemy_.GetName() << std::endl
            << "he was carrying the following items: " << std::endl;
            auto items = enemy_.TransferItems();
            for(int i = 0; i < items.size(); ++i) {
                output_ << items.get(i).GetName();
                if (i != items.size() - 1) {
                    output_ << ", ";
                }

                player_.currentLocation->AddVisibleItem(items.pop(i));
            }
            output_ << std::endl;
        }
    }
} // frontend