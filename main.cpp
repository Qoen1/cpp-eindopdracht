#include <iostream>

#include "backend/enemy/Enemy.hpp"
#include "backend/location/Location.hpp"
#include "helpers/BigBrainPointer.hpp"


int main()
{
    auto location = new backend::Location(new std::string("naam"), new std::string(" beshcrijving"));

    const std::string& name {location->getName()};

    location->getName().append("-");
    //
    // name = "reee";

    std::cout << name;

    return 0;
}
