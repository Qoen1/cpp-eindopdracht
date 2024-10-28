//
// Created by koenv on 05/10/2024.
//

#ifndef SPELOBJECT_HPP
#define SPELOBJECT_HPP
#include "../../helpers/TypoTrap.hpp"

namespace backend {

class Item {
public:
    helpers::TypoTrap Name;
    helpers::TypoTrap Description;

    virtual helpers::TypoTrap* ToString() = 0;
};

} // backend

#endif //SPELOBJECT_HPP
