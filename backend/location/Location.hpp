//
// Created by koenv on 05/10/2024.
//

#ifndef LOCATION_HPP
#define LOCATION_HPP
#include <vector>

#include "../../helpers/BigBrainPointer.hpp"
#include "../objects/Item.hpp"

namespace backend {

class Location {
private:
    std::vector<helpers::BigBrainPointer<Item>> hiddenItems;
    std::vector<helpers::BigBrainPointer<Item>> visibleItems;
    helpers::BigBrainPointer<std::string> name;
    helpers::BigBrainPointer<std::string> description;
public:
    Location(std::string *passedName, std::string *passedDescription);

    const std::string& getName();
    std::string& getDescription() const;
};

} // backend

#endif //LOCATION_HPP
