//
// Created by koenv on 05/10/2024.
//

#ifndef ENEMY_HPP
#define ENEMY_HPP
#include <string>
#include <vector>

#include "../../helpers/BigBrainPointer.hpp"
#include "../../helpers/DynamicDoodad.hpp"
#include "../objects/Item.hpp"

namespace backend {

class Enemy {
private:
    helpers::DynamicDoodad<helpers::BigBrainPointer<Item>> items;
    helpers::BigBrainPointer<helpers::TypoTrap> name;
    helpers::BigBrainPointer<helpers::TypoTrap> description;
    int health;
public:
    Enemy(helpers::TypoTrap *name, helpers::TypoTrap *description, int health);
    void AddItem(helpers::BigBrainPointer<Item>&& item);
    helpers::DynamicDoodad<helpers::BigBrainPointer<Item>> TransferItems();
    int GetHealth() const;
    const helpers::TypoTrap &GetName() const;
    const helpers::TypoTrap &GetDescription() const;
};

} // backend

#endif //ENEMY_HPP
