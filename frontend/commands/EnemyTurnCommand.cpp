//
// Created by koenv on 26/01/2025.
//

#include "EnemyTurnCommand.hpp"

#include <iostream>

#include "../../backend/Game.hpp"
#include "../player/Player.hpp"

namespace frontend {
    EnemyTurnCommand::EnemyTurnCommand(backend::Game &game, Player& player)
        : game_(game), player_(player) {
    }

    void EnemyTurnCommand::Execute() {
        auto current_room = player_.currentLocation;
        auto enemies = current_room->GetEnemies();
        if (enemies.size() > 0) {
            for (auto i = 0; i < enemies.size(); ++i) {
                auto enemy = enemies.get(i);
                auto damage = enemy->Attack();
                if (damage > 0) std::cout << "The " << enemy->GetName() << " attacks you for " << damage << " damage" << std::endl;
                player_.TakeDamage(damage);
            }
        }else {
            game_.MoveEnemies();
        }

    }
} // frontend