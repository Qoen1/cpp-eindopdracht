#include <iostream>

#include "backend/enemy/Enemy.hpp"
#include "backend/location/Location.hpp"
#include "helpers/BigBrainPointer.hpp"


int main()
{
    auto location = new backend::Location(new helpers::TypoTrap("je moeder"), new helpers::TypoTrap(" beschrijving"));

    const helpers::TypoTrap& name {location->getName()};

    // location->getName().append("-");
    //
    // name = "reee";
    std::cout << name.cstring() << name.size();

    return 0;
}
