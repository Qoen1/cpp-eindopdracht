//
// Created by koenv on 05/10/2024.
//

#ifndef ARMOR_HPP
#define ARMOR_HPP
#include "Item.hpp"
#include "../../helpers/BigBrainPointer.hpp"

namespace backend {

class Armor : public Item {
public:
    Armor(const helpers::TypoTrap &name, const helpers::TypoTrap &description, int defense);
    int GetDefense() const;

    ~Armor() override = default;
private:
    int defense_;
};

} // backend

#endif //ARMOR_HPP
