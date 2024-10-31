//
// Created by koenv on 05/10/2024.
//

#ifndef LOCATION_HPP
#define LOCATION_HPP

#include "../../helpers/BigBrainPointer.hpp"
#include "../../helpers/DynamicDoodad.hpp"
#include "../../helpers/TypoTrap.hpp"
#include "../enemy/Enemy.hpp"
#include "../objects/Item.hpp"

namespace backend {

class Location {
private:
    helpers::BigBrainPointer<helpers::DynamicDoodad<Item*>> hiddenItems_;
    helpers::BigBrainPointer<helpers::DynamicDoodad<Item*>> visibleItems_;
    helpers::BigBrainPointer<helpers::DynamicDoodad<Enemy*>> enemies_;
    helpers::BigBrainPointer<helpers::TypoTrap> name_;
    helpers::BigBrainPointer<helpers::TypoTrap> description_;
    helpers::BigBrainPointer<helpers::DynamicDoodad<Location*>> neighbors_;
public:
    Location(helpers::TypoTrap* passedName, helpers::TypoTrap* passedDescription);
    void AddHiddenItem(Item* passedItem);
    const helpers::DynamicDoodad<Item*> &GetHiddenItems();
    void AddVisibleItem(Item* passedItem);
    const helpers::DynamicDoodad<Item*> &GetVisibleItems();
    void AddEnemy(Enemy* passedEnemy);

    const Item* GetItemByName(const helpers::TypoTrap &passedName) const;
    Enemy* GetEnemyByName(const helpers::TypoTrap &passedName) const;

    void MakeItemVisible(const Item &passedItem);
    void MakeItemInvisible(const Item &passedItem);

    const helpers::TypoTrap& getName();
    helpers::TypoTrap& getDescription() const;
};

} // backend

#endif //LOCATION_HPP
