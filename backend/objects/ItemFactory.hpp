//
// Created by koenv on 05/10/2024.
//

#ifndef ITEMFACTORY_HPP
#define ITEMFACTORY_HPP
#include "Item.hpp"
#include "../../helpers/BigBrainPointer.hpp"

namespace backend {

class ItemFactory {
public:
    helpers::BigBrainPointer<Item> Create(const helpers::TypoTrap& type, const helpers::TypoTrap& name, const helpers::TypoTrap& description, int value);
    helpers::BigBrainPointer<Item> Create(const ItemTypeDTO& dto);

};

} // backend

#endif //ITEMFACTORY_HPP
