//
// Created by koenv on 05/10/2024.
//

#ifndef WEAPON_HPP
#define WEAPON_HPP
#include "Item.hpp"
#include "../../helpers/BigBrainPointer.hpp"

namespace backend {

class Weapon: public Item{
public:
    Weapon(const helpers::TypoTrap &name, const helpers::TypoTrap &description, int damage);

    ~Weapon() override = default;

    int GetAttackDamage() const;
private:
    int damage_;
};

} // backend

#endif //WEAPON_HPP
