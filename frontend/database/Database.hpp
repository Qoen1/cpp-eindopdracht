

#ifndef DATABASE_HPP
#define DATABASE_HPP
#include <memory>
#include <sqlite3.h>
#include <vector>

#include "../../backend/location/Location.hpp"

struct Score;

namespace frontend {

class Database {
public:
    Database(std::string path);
    ~Database();
    std::vector<std::unique_ptr<backend::Location>> GetLocations();
    std::vector<backend::ItemTypeDTO> GetItems();
    backend::ItemTypeDTO GetItem(const std::string& name);
    std::vector<backend::EnemyTypeDTO> GetEnemies();
    backend::EnemyTypeDTO GetEnemy(const std::string& name);
    void AddScore(Score score);
    std::vector<Score> GetScores();

private:
    std::string path_;
    sqlite3* connection_;
};

} // frontend

#endif //DATABASE_HPP
