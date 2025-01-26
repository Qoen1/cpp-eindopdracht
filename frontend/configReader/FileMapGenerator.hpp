//
// Created by fikkie on 28/10/24.
//

#ifndef FILEMAPGENERATOR_HPP
#define FILEMAPGENERATOR_HPP
#include <map>

#include "IMapGenerator.hpp"
#include "../database/Database.hpp"


class FileMapGenerator : IMapGenerator {
public:
    FileMapGenerator(const std::string& fileName, std::shared_ptr<frontend::Database> database);
    std::vector<std::unique_ptr<backend::Location>> Generate() override;
private:
    std::string fileName;
    std::shared_ptr<frontend::Database> database;
    std::map<std::string, int> name_occurences;

    std::vector<std::string> split(const std::string& s, char delimiter);
    helpers::BigBrainPointer<backend::Enemy> create_enemy(backend::EnemyTypeDTO dto, helpers::DynamicDoodad<backend::ItemTypeDTO>& possible_items);
    helpers::BigBrainPointer<backend::Item> create_item(backend::ItemTypeDTO dto);
};



#endif //FILEMAPGENERATOR_HPP
