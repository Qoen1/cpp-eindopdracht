//
// Created by koenv on 05/10/2024.
//

#include "Enemy.hpp"

#include <algorithm>

namespace backend {
    Enemy::Enemy(): health(0), damage(0), name(helpers::TypoTrap()), description(helpers::TypoTrap()), items(helpers::OwningDynamicDoodad<Item>()) {
    }

    Enemy::Enemy(const helpers::TypoTrap& name, const helpers::TypoTrap& description, int health, int damage) : items(helpers::OwningDynamicDoodad<Item>()), name(name),
                                                                                                                description(description), health(health), damage(damage) {
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
        return name;
    }

    const helpers::TypoTrap & Enemy::GetDescription() const {
        return description;
    }
} // backend