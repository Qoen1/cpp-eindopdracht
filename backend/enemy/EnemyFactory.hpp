//
// Created by koenv on 05/10/2024.
//

#ifndef ENEMYFACTORY_HPP
#define ENEMYFACTORY_HPP
#include "Enemy.hpp"
#include "../../helpers/BigBrainPointer.hpp"

namespace backend {

class EnemyFactory {
public:
    helpers::BigBrainPointer<Enemy> Create(const helpers::TypoTrap& name, const helpers::TypoTrap& description, int health, int damage, int attack_chance, helpers::OwningDynamicDoodad<Item> items);
    helpers::BigBrainPointer<Enemy> Create(const EnemyTypeDTO& dto, const helpers::DynamicDoodad<ItemTypeDTO>& possible_items);

};

} // backend

#endif //ENEMYFACTORY_HPP
