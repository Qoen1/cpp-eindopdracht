//
// Created by fikkie on 28/10/24.
//

#ifndef FILEMAPGENERATOR_HPP
#define FILEMAPGENERATOR_HPP
#include "IMapGenerator.hpp"


class FileMapGenerator : IMapGenerator {
private:
    std::string fileName;
public:
    FileMapGenerator(std::string fileName);
};



#endif //FILEMAPGENERATOR_HPP
