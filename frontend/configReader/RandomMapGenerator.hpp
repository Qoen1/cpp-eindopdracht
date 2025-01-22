//
// Created by fikkie on 28/10/24.
//

#ifndef RANDOMMAPGENERATOR_HPP
#define RANDOMMAPGENERATOR_HPP
#include "IMapGenerator.hpp"


class RandomMapGenerator : IMapGenerator{
public:
    std::vector<std::unique_ptr<backend::Location>> Generate() override;
};



#endif //RANDOMMAPGENERATOR_HPP
