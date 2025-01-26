//
// Created by koenv on 25/01/2025.
//

#include "AttackCommand.hpp"
#include "../player/Player.hpp"
#include "../../backend/enemy/Enemy.hpp"

namespace frontend {
    AttackCommand::AttackCommand(Player &actor, backend::Enemy &victim): player_(actor), enemy_(victim) {}

    void AttackCommand::Execute() {
        //TODO: add miss chance
        enemy_.TakeDamage(player_.Attack());
    }
} // frontend