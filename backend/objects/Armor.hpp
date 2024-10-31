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
    Armor(helpers::TypoTrap &name, helpers::TypoTrap &description);

    const helpers::TypoTrap & GetName() const override;

    const helpers::TypoTrap & GetDescription() const override;
private:
    helpers::BigBrainPointer<helpers::TypoTrap> name_;
    helpers::BigBrainPointer<helpers::TypoTrap> description_;
};

} // backend

#endif //ARMOR_HPP
