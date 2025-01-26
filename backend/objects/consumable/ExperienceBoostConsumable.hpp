//
// Created by koenv on 26/01/2025.
//

#ifndef EXPERIENCEBOOSTCONSUMABLE_HPP
#define EXPERIENCEBOOSTCONSUMABLE_HPP
#include "Consumable.hpp"

namespace backend {

class ExperienceBoostConsumable: public Consumable {
public:
    ExperienceBoostConsumable(const helpers::TypoTrap &name, const helpers::TypoTrap &description, int boost_amount);

    void Consume(frontend::Player &player) override;
private:
    int experienceBoost;
};

} // backend

#endif //EXPERIENCEBOOSTCONSUMABLE_HPP
