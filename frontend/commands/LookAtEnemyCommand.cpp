//
// Created by koenv on 31/10/2024.
//

#include "LookAtEnemyCommand.hpp"

#include <iostream>

namespace frontend {
    LookAtEnemyCommand::LookAtEnemyCommand(backend::Enemy &enemy, Player& player) : enemy_{enemy}, player_(player) {
    }

    void LookAtEnemyCommand::Execute() {
        if(enemy_.GetHealth() > 0) std::cout << enemy_.GetDescription() << std::endl;
        else {
            std::cout << "You see the remains of " << enemy_.GetName() << std::endl
            << "he was carrying the following items: " << std::endl;
            auto items = enemy_.TransferItems();
            for(int i = 0; i < items.size(); ++i) {
                std::cout << items.get(i).GetName();
                if (i != items.size() - 1) {
                    std::cout << ", ";
                }

                player_.currentLocation->AddVisibleItem(items.pop(i));
            }
            std::cout << std::endl;
        }
    }
} // frontend