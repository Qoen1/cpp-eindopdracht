//
// Created by fikkie on 28/10/24.
//

#include "RandomMapGenerator.hpp"

#include "../../backend/location/LocationFactory.hpp"


RandomMapGenerator::RandomMapGenerator(): database_("kerkersendraken.db") {
}

std::vector<std::unique_ptr<backend::Location>> RandomMapGenerator::Generate() {
    auto locations = database_.GetLocations();

    GenerateConnections(locations);

    return locations;
}

void RandomMapGenerator::GenerateConnections(std::vector<std::unique_ptr<backend::Location>>& locations) {
    auto& start = *locations[0];
    start.AddNeighbor(SOUTH, *locations[1]);
    start.AddNeighbor(WEST, *locations[2]);
    start.AddNeighbor(NORTH, *locations[3]);
    start.AddNeighbor(EAST, *locations[4]);

    locations[1]->AddNeighbor(NORTH, *locations[0]);
    locations[2]->AddNeighbor(EAST, *locations[0]);
    locations[3]->AddNeighbor(SOUTH, *locations[0]);
    locations[4]->AddNeighbor(WEST, *locations[0]);
}

void RandomMapGenerator::GenerateItems(std::vector<std::unique_ptr<backend::Location>>& locations) {
    //TODO: implement
}

void RandomMapGenerator::GenerateEnemies(std::vector<std::unique_ptr<backend::Location>>& locations) {
    //TODO: implement
}