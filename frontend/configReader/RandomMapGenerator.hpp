//
// Created by fikkie on 28/10/24.
//

#ifndef RANDOMMAPGENERATOR_HPP
#define RANDOMMAPGENERATOR_HPP
#include "IMapGenerator.hpp"
#include "../database/Database.hpp"


class RandomMapGenerator : IMapGenerator{
public:
    RandomMapGenerator();
    std::vector<std::unique_ptr<backend::Location>> Generate() override;
private:
    frontend::Database database_;

    void GenerateConnections(std::vector<std::unique_ptr<backend::Location>>& locations);
    void GenerateItems(std::vector<std::unique_ptr<backend::Location>>& locations);
    void GenerateEnemies(std::vector<std::unique_ptr<backend::Location>>& locations);
};



#endif //RANDOMMAPGENERATOR_HPP
