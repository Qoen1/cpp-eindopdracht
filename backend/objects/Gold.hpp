//
// Created by koenv on 05/10/2024.
//

#ifndef GOLD_HPP
#define GOLD_HPP
#include "Item.hpp"

namespace backend {

class Gold: public Item {
public:
    Gold(const helpers::TypoTrap& name, const helpers::TypoTrap& description, int amount);
    int GetValue() const;
    ~Gold() override = default;

private:
    int amount_;
};

} // backend

#endif //GOLD_HPP
