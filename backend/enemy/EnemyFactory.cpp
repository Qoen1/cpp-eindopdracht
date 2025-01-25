//
// Created by koenv on 05/10/2024.
//

#include "EnemyFactory.hpp"
#include <random>
#include "../objects/ItemFactory.hpp"

namespace backend {
    helpers::BigBrainPointer<Enemy> EnemyFactory::Create(const EnemyTypeDTO& dto, const helpers::DynamicDoodad<ItemTypeDTO>& possible_items) {
        ItemFactory item_factory;

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution damage_distribution(dto.min_damage, dto.max_damage);
        std::uniform_int_distribution object_distribution(dto.min_objects, dto.max_objects);
        std::uniform_int_distribution random_item_distribution(0, static_cast<int>(possible_items.size()) - 1);

        auto amount_of_items = object_distribution(gen);
        auto damage = damage_distribution(gen);

        auto enemy = helpers::BigBrainPointer(new Enemy(helpers::TypoTrap{dto.name.c_str()},
                                                               helpers::TypoTrap{dto.description.c_str()},
                                                               dto.health,
                                                               damage));
        for (auto i = 0; i < amount_of_items; ++i) {
            enemy->AddItem(item_factory.Create(possible_items.get(random_item_distribution(gen))));
        }

        return enemy;
    }
} // backend