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
    helpers::BigBrainPointer<Enemy> Create();
    helpers::BigBrainPointer<Enemy> Create(const EnemyTypeDTO& dto, const helpers::DynamicDoodad<ItemTypeDTO>& possible_items);

};

} // backend

#endif //ENEMYFACTORY_HPP
