//
// Created by fikkie on 28/10/24.
//

#ifndef RANDOMMAPGENERATOR_HPP
#define RANDOMMAPGENERATOR_HPP
#include <map>

#include "IMapGenerator.hpp"
#include "../database/Database.hpp"


class RandomMapGenerator : IMapGenerator{
public:
    RandomMapGenerator(std::shared_ptr<frontend::Database> database);
    std::vector<std::unique_ptr<backend::Location>> Generate() override;
private:
    std::shared_ptr<frontend::Database> database_;
    std::map<std::string, int> name_occurences;

    void GenerateConnections(std::vector<std::unique_ptr<backend::Location>>& locations);
    helpers::BigBrainPointer<backend::Item> GenerateItem(backend::ItemTypeDTO item);
    helpers::BigBrainPointer<backend::Enemy> GenerateEnemy(backend::EnemyTypeDTO enemy, std::vector<backend::ItemTypeDTO> item_options);

};



#endif //RANDOMMAPGENERATOR_HPP
