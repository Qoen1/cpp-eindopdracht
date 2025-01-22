//
// Created by koenv on 05/10/2024.
//

#include "Enemy.hpp"

#include <algorithm>

namespace backend {
    Enemy::Enemy(helpers::TypoTrap *name, helpers::TypoTrap *description, int health) : items(helpers::OwningDynamicDoodad<Item>()), name(name),
        description(description), health(health) {
    }

    void Enemy::AddItem(helpers::BigBrainPointer<Item>&& item) {
        items.push_back(static_cast<helpers::BigBrainPointer<Item>&&>(item));
    }

     helpers::OwningDynamicDoodad<Item> Enemy::TransferItems() {
        auto temp = std::move(items);
        items = helpers::OwningDynamicDoodad<Item>();
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