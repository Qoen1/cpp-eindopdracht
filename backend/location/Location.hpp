//
// Created by koenv on 05/10/2024.
//

#ifndef LOCATION_HPP
#define LOCATION_HPP

#include "../Direction.hpp"
#include "../Door.hpp"
#include "../../helpers/BigBrainPointer.hpp"
#include "../../helpers/DynamicDoodad.hpp"
#include "../../helpers/TypoTrap.hpp"
#include "../enemy/Enemy.hpp"
#include "../objects/Item.hpp"

namespace backend {

class Location {
private:
    helpers::OwningDynamicDoodad<Item> hiddenItems_;
    helpers::OwningDynamicDoodad<Item> visibleItems_;
    helpers::OwningDynamicDoodad<Enemy> enemies_;
    helpers::TypoTrap name_;
    helpers::TypoTrap description_;
    helpers::OwningDynamicDoodad<Door> neighbors_;
public:
    Location(const helpers::TypoTrap& passedName, const helpers::TypoTrap& passedDescription);
    void AddHiddenItem(helpers::BigBrainPointer<Item>&& passedItem);
    helpers::DynamicDoodad<Item*> GetHiddenItems();
    void AddVisibleItem(helpers::BigBrainPointer<Item>&& passedItem);
    helpers::DynamicDoodad<Item*> GetVisibleItems();
    void AddEnemy(helpers::BigBrainPointer<Enemy>&& passedEnemy);
    helpers::DynamicDoodad<Enemy*> GetEnemies();

    helpers::BigBrainPointer<Item> PopItemByName(const helpers::TypoTrap &passedName);
    const Item* GetItemByName(const helpers::TypoTrap &passedName) const;
    Enemy* GetEnemyByName(const helpers::TypoTrap &passedName) const;

    void MakeItemVisible(const Item &passedItem);
    void MakeItemInvisible(const Item &passedItem);
    std::vector<Item*> MakeAllItemsVisible();

    Location* GetNeighbor(Direction passedDirection) const;
    void AddNeighbor(Direction passedDirection, Location& passedLocation);
    helpers::DynamicDoodad<Direction> GetDirections() const;

    const helpers::TypoTrap& getName() const;
    const helpers::TypoTrap& getDescription() const;
};

} // backend

#endif //LOCATION_HPP
