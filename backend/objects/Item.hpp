//
// Created by koenv on 05/10/2024.
//

#ifndef SPELOBJECT_HPP
#define SPELOBJECT_HPP
#include "../../helpers/TypoTrap.hpp"

namespace backend {

class Item {
public:
    virtual const helpers::TypoTrap& GetName() const = 0;
    virtual const helpers::TypoTrap& GetDescription() const = 0;
};

} // backend

#endif //SPELOBJECT_HPP
