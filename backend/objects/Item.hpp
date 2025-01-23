//
// Created by koenv on 05/10/2024.
//

#ifndef SPELOBJECT_HPP
#define SPELOBJECT_HPP
#include "../../helpers/TypoTrap.hpp"

namespace backend {
struct ItemTypeDTO {
    std::string name;
    std::string description;
    std::string type;
    int minimum_value;
    int maximum_value;
    int protection;
};
class Item {
public:
    Item(const helpers::TypoTrap& name, const helpers::TypoTrap& description);
    [[nodiscard]] virtual const helpers::TypoTrap& GetName() const;
    [[nodiscard]] virtual const helpers::TypoTrap& GetDescription() const;

private:
    helpers::TypoTrap name_;
    helpers::TypoTrap description_;
};

} // backend

#endif //SPELOBJECT_HPP
