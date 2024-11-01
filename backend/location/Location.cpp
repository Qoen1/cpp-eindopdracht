//
// Created by koenv on 05/10/2024.
//

#include "Location.hpp"

namespace backend {

    Location::Location(helpers::TypoTrap* passedName,
                       helpers::TypoTrap* passedDescription) : hiddenItems_(new helpers::DynamicDoodad<Item*>(0)), visibleItems_(new helpers::DynamicDoodad<Item*>(0)), enemies_(new helpers::DynamicDoodad<Enemy*>(0)),
                                                               name_(passedName), description_(passedDescription), neighbors_(new helpers::DynamicDoodad<Door*>(0)) {
    }

    void Location::AddHiddenItem(Item* passedItem) {
        hiddenItems_->push_back(passedItem);
    }

    void Location::AddVisibleItem(Item* passedItem) {
        visibleItems_->push_back(passedItem);
    }

    const helpers::DynamicDoodad<Item*>& Location::GetHiddenItems() {
        return *hiddenItems_;
    }

    const helpers::DynamicDoodad<Item*> & Location::GetVisibleItems() {
        return *visibleItems_;
    }

    void Location::AddEnemy(Enemy *passedEnemy) {
        enemies_->push_back(passedEnemy);
    }

    const Item * Location::GetItemByName(const helpers::TypoTrap &passedName) const {
        for (int i = 0; i < visibleItems_->size(); ++i) {
            if(visibleItems_->get(i)->GetName() == passedName) {
                return visibleItems_->get(i);
            }
        }
        return nullptr;
    }

    Enemy * Location::GetEnemyByName(const helpers::TypoTrap &passedName) const {
        for (int i = 0; i < enemies_->size(); ++i) {
            if(enemies_->get(i)->GetName() == passedName) {
                return enemies_->get(i);
            }
        }
        return nullptr;
    }

    void Location::MakeItemVisible(const Item &passedItem) {
        for (int i = 0; i < hiddenItems_->size(); ++i) {
            if(hiddenItems_->get(i) == &passedItem) {
                visibleItems_->push_back(hiddenItems_->get(i));
                hiddenItems_->erase(i);
                return;
            }
        }
    }

    void Location::MakeItemInvisible(const Item &passedItem) {
        for (int i = 0; i < visibleItems_->size(); ++i) {
            if(visibleItems_->get(i) == &passedItem) {
                hiddenItems_->push_back(visibleItems_->get(i));
                visibleItems_->erase(i);
                return;
            }
        }
    }

    void Location::MakeAllItemsVisible() {
        for (int i = 0; i < hiddenItems_->size(); ++i) {visibleItems_->push_back(hiddenItems_->get(i));}
        for (int i = 0; i < hiddenItems_->size(); ++i) {hiddenItems_->erase(i);}
    }

    Location * Location::GetNeighbor(Direction passedDirection) const {
        for (int i = 0; i < neighbors_->size(); ++i) {
            if(neighbors_->get(i)->direction_ == passedDirection) {
                return &neighbors_->get(i)->location_;
            }
        }
        throw std::invalid_argument("Direction is not valid");
    }

    void Location::AddNeighbor(Direction passedDirection, Location* passedLocation) {
        neighbors_->push_back(new Door(*passedLocation, passedDirection));
    }


    const helpers::TypoTrap & Location::getName() {
        return *name_;
    }

    helpers::TypoTrap & Location::getDescription() const {
        return *description_;
    }
} // backend