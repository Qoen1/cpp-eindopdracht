//
// Created by koenv on 05/10/2024.
//

#include "Enemy.hpp"

#include <algorithm>

namespace backend {
    Enemy::Enemy(helpers::TypoTrap *name, helpers::TypoTrap *description, int health) : items(new helpers::DynamicDoodad<Item *>(0)), name(name),
        description(description), health(health) {
    }

    void Enemy::AddItem(Item *item) {
        items->push_back(item);
    }

    helpers::BigBrainPointer<helpers::DynamicDoodad<Item *>> Enemy::TransferItems() {
        auto temp = std::move(items);
        items = helpers::BigBrainPointer(new helpers::DynamicDoodad<Item *>(0));
        return temp;
    }

    int Enemy::GetHealth() const {
        return health;
    }

    const helpers::TypoTrap & Enemy::GetName() const {
        return *name;
    }

    const helpers::TypoTrap & Enemy::GetDescription() const {
        return *description;
    }
} // backend