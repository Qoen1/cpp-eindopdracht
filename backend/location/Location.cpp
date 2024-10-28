//
// Created by koenv on 05/10/2024.
//

#include "Location.hpp"

#include <bits/ranges_algobase.h>

namespace backend {

    Location::Location(helpers::TypoTrap* passedName,
                       helpers::TypoTrap* passedDescription) : hiddenItems(0), visibleItems(0), name(passedName),
                                                               description(passedDescription), neighbors(0) {
    }

    void Location::AddHiddenItem(Item* passedItem) {
        hiddenItems.push_back(passedItem);
    }

    void Location::AddVisibleItem(Item* passedItem) {
        visibleItems.push_back(passedItem);
    }

    const helpers::DynamicDoodad<Item*>& Location::GetHiddenItems() {
        return hiddenItems;
    }

    const helpers::DynamicDoodad<Item*> & Location::GetVisibleItems() {
        return visibleItems;
    }

    void Location::MakeItemVisible(const Item &passedItem) {
        for (int i = 0; i < hiddenItems.size(); ++i) {
            if(&*hiddenItems.get(i) == &passedItem) {
                visibleItems.push_back(hiddenItems.get(i));
                hiddenItems.erase(i);
                return;
            }
        }
    }

    void Location::MakeItemInvisible(const Item &passedItem) {
        for (int i = 0; i < visibleItems.size(); ++i) {
            if(&*visibleItems.get(i) == &passedItem) {
                hiddenItems.push_back(visibleItems.get(i));
                visibleItems.erase(i);
                return;
            }
        }
    }

    const helpers::TypoTrap & Location::getName() {
        return *name;
    }

    helpers::TypoTrap & Location::getDescription() const {
        return *description;
    }
} // backend