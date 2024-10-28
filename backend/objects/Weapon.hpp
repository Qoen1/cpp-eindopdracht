//
// Created by koenv on 05/10/2024.
//

#ifndef WEAPON_HPP
#define WEAPON_HPP
#include "Item.hpp"

namespace backend {

class Weapon: public Item{
public:
    helpers::TypoTrap* ToString() override;
};

} // backend

#endif //WEAPON_HPP
