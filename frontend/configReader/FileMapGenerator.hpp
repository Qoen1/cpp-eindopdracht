//
// Created by fikkie on 28/10/24.
//

#ifndef FILEMAPGENERATOR_HPP
#define FILEMAPGENERATOR_HPP
#include "IMapGenerator.hpp"
#include "../database/Database.hpp"


class FileMapGenerator : IMapGenerator {
public:
    FileMapGenerator(const std::string& fileName, const std::string& db_fileName);
    std::vector<std::unique_ptr<backend::Location>> Generate() override;
private:
    std::string fileName;
    frontend::Database database;

    std::vector<std::string> split(const std::string& s, char delimiter);
};



#endif //FILEMAPGENERATOR_HPP
