//
// Created by fikkie on 28/10/24.
//

#ifndef IMAPGENERATOR_HPP
#define IMAPGENERATOR_HPP
#include <memory>
#include <vector>

#include "../../backend/location/Location.hpp"


class IMapGenerator {
public:
    virtual std::vector<backend::Location*>* Generate() = 0;
};



#endif //IMAPGENERATOR_HPP
