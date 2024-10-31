//
// Created by koenv on 31/10/2024.
//

#include "LookAtEnemyCommand.hpp"

#include <iostream>

namespace frontend {
    LookAtEnemyCommand::LookAtEnemyCommand(backend::Enemy &enemy, Player& player) : enemy_{enemy}, player_(player) {
    }

    void LookAtEnemyCommand::Execute() {
        if(enemy_.GetHealth() > 0) std::cout << enemy_.GetDescription().cstring() << std::endl;
        else {
            std::cout << "You see the remains of " << enemy_.GetName().cstring() << std::endl;
            auto items = enemy_.TransferItems();
            for(int i = 0; i < items->size(); ++i) {
                player_.currentLocation.AddVisibleItem(items->get(i));
            }
        }
    }
} // frontend