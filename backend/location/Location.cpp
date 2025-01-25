//
// Created by koenv on 05/10/2024.
//

#include "Location.hpp"

namespace backend {
    Location::Location(const helpers::TypoTrap& passedName,
                       const helpers::TypoTrap& passedDescription) : hiddenItems_(helpers::OwningDynamicDoodad<Item>()),
                                                               visibleItems_(helpers::OwningDynamicDoodad<Item>()),
                                                               enemies_(helpers::OwningDynamicDoodad<Enemy>()),
                                                               name_(passedName), description_(passedDescription),
                                                               neighbors_(helpers::OwningDynamicDoodad<Door>()) {
    }

    void Location::AddHiddenItem(helpers::BigBrainPointer<Item>&& passedItem) {
        hiddenItems_.push_back(static_cast<helpers::BigBrainPointer<Item>&&>(passedItem));
    }

    void Location::AddVisibleItem(helpers::BigBrainPointer<Item>&& passedItem) {
        visibleItems_.push_back(static_cast<helpers::BigBrainPointer<Item>&&>(passedItem));
    }

    helpers::DynamicDoodad<Item> Location::GetHiddenItems() {
        helpers::DynamicDoodad<Item> list;
        for (auto it = 0; it < hiddenItems_.size(); it++) {
            list.push_back(hiddenItems_.get(it));
        }
        return list;
    }

    helpers::DynamicDoodad<Item> Location::GetVisibleItems() {
        helpers::DynamicDoodad<Item> list;
        for (auto it = 0; it < visibleItems_.size(); it++) {
            list.push_back(visibleItems_.get(it));
        }
        return list;
    }

    void Location::AddEnemy(helpers::BigBrainPointer<Enemy>&& passedEnemy) {
        enemies_.push_back(static_cast<helpers::BigBrainPointer<Enemy>&&>(passedEnemy));
    }

    helpers::DynamicDoodad<Enemy> Location::GetEnemies() {
        helpers::DynamicDoodad<Enemy> list;
        for (auto it = 0; it < enemies_.size(); it++) {
            list.push_back(enemies_.get(it));
        }
        return list;
    }

    helpers::BigBrainPointer<Item> Location::PopItemByName(const helpers::TypoTrap &passedName) {
        for (int i = 0; i < visibleItems_.size(); ++i) {
            if(visibleItems_.get(i).GetName() == passedName) {
                return visibleItems_.pop(i);
            }
        }
        return nullptr;
    }

    const Item * Location::GetItemByName(const helpers::TypoTrap &passedName) const {
        for (int i = 0; i < visibleItems_.size(); ++i) {
            if(visibleItems_.get(i).GetName() == passedName) {
                return &visibleItems_.get(i);
            }
        }
        return nullptr;
    }

    Enemy* Location::GetEnemyByName(const helpers::TypoTrap &passedName) const {
        for (int i = 0; i < enemies_.size(); ++i) {
            if(enemies_.get(i).GetName() == passedName) {
                return &enemies_.get(i);
            }
        }
        return nullptr;
    }

    void Location::MakeItemVisible(const Item &passedItem) {
        for (int i = 0; i < hiddenItems_.size(); ++i) {
            if(hiddenItems_.get(i).GetName() == passedItem.GetName()) {
                visibleItems_.push_back((hiddenItems_.pop(i)));
                hiddenItems_.erase(i);
                return;
            }
        }
    }

    void Location::MakeItemInvisible(const Item &passedItem) {
        for (int i = 0; i < visibleItems_.size(); ++i) {
            if(visibleItems_.get(i).GetName() == passedItem.GetName()) {
                hiddenItems_.push_back(visibleItems_.pop(i));
                visibleItems_.erase(i);
                return;
            }
        }
    }

    void Location::MakeAllItemsVisible() {
        for (int i = 0; i < hiddenItems_.size(); ++i) {visibleItems_.push_back(hiddenItems_.pop(i));}
        for (int i = 0; i < hiddenItems_.size(); ++i) {hiddenItems_.erase(i);}
    }

    Location * Location::GetNeighbor(Direction passedDirection) const {
        for (int i = 0; i < neighbors_.size(); ++i) {
            if(neighbors_.get(i).direction_ == passedDirection) {
                return &neighbors_.get(i).location_;
            }
        }
        throw std::invalid_argument("Direction is not valid");
    }

    void Location::AddNeighbor(Direction passedDirection, Location& passedLocation) {
        neighbors_.push_back(helpers::BigBrainPointer(new Door(passedLocation, passedDirection)));
    }

    helpers::DynamicDoodad<Direction> Location::GetDirections() const {
        helpers::DynamicDoodad<Direction> list;
        for (int i = 0; i < neighbors_.size(); ++i) {
            list.push_back(neighbors_.get(i).direction_);
        }
        return list;
    }


    const helpers::TypoTrap& Location::getName() const {
        return name_;
    }

    const helpers::TypoTrap& Location::getDescription() const {
        return description_;
    }
} // backend