//
// Created by fikkie on 28/10/24.
//

#include "RegularState.hpp"
#include <random>
#include "Player.hpp"

RegularState::RegularState(frontend::Player &player)
    : player_(player) {
}

void RegularState::TakeDamage(int damage) {
    auto* armor = player_.GetArmor();
    if (armor) damage -= armor->GetDefense();
    if (damage < 0) damage = 0;
    player_.SetHitpoints(player_.GetHitpoints() - damage);
    if (player_.GetHitpoints() <= 0) {
        player_.SetHitpoints(0);
    }
}

int RegularState::Attack() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 100);
    int result = dis(gen);
    if (result <= player_.GetAttackChance()) {
        return player_.GetAttackDamage();
    }
    return 0;
}
