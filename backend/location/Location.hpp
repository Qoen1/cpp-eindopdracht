//
// Created by koenv on 05/10/2024.
//

#ifndef LOCATION_HPP
#define LOCATION_HPP
#include <vector>

#include "../../helpers/BigBrainPointer.hpp"
#include "../../helpers/TypoTrap.hpp"
#include "../objects/Item.hpp"

namespace backend {

class Location {
private:
    std::vector<helpers::BigBrainPointer<Item>> hiddenItems;
    std::vector<helpers::BigBrainPointer<Item>> visibleItems;
    helpers::BigBrainPointer<helpers::TypoTrap> name;
    helpers::BigBrainPointer<helpers::TypoTrap> description;
public:
    Location(helpers::TypoTrap *passedName, helpers::TypoTrap *passedDescription);

    const helpers::TypoTrap& getName();
    helpers::TypoTrap& getDescription() const;
};

} // backend

#endif //LOCATION_HPP
