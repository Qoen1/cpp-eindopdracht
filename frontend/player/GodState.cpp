//
// Created by fikkie on 28/10/24.
//

#include "GodState.hpp"

#include "Player.hpp"

GodState::GodState(frontend::Player &player): player_(player) {
}

void GodState::TakeDamage(int damage) {/* do nothing */}

int GodState::Attack() {
    return player_.GetAttackDamage();
}
