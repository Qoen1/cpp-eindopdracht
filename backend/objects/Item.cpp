//
// Created by koenv on 05/10/2024.
//

#include "Item.hpp"

namespace backend {
    Item::Item(const helpers::TypoTrap& name, const helpers::TypoTrap& description): name_({name}),
        description_({description}) {}

    const helpers::TypoTrap& Item::GetName() const {
        return name_;
    }

    const helpers::TypoTrap& Item::GetDescription() const {
        return description_;
    }
} // backend
