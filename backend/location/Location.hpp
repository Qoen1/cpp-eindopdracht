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
    helpers::DynamicDoodad<Item*> hiddenItems;
    helpers::DynamicDoodad<Item*> visibleItems;
    helpers::DynamicDoodad<Enemy*> enemies;
    helpers::BigBrainPointer<helpers::TypoTrap> name;
    helpers::BigBrainPointer<helpers::TypoTrap> description;
    helpers::DynamicDoodad<Location*> neighbors;
public:
    Location(helpers::TypoTrap* passedName, helpers::TypoTrap* passedDescription);
    void AddHiddenItem(Item* passedItem);
    const helpers::DynamicDoodad<Item*> &GetHiddenItems();
    void AddVisibleItem(Item* passedItem);
    const helpers::DynamicDoodad<Item*> &GetVisibleItems();

    const Item* GetItemByName(const std::string &passedName) const;
    Enemy* GetEnemyByName(const std::string &passedName) const;

    void MakeItemVisible(const Item &passedItem);
    void MakeItemInvisible(const Item &passedItem);

    const helpers::TypoTrap& getName();
    helpers::TypoTrap& getDescription() const;
};

} // backend

#endif //LOCATION_HPP
