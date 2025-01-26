#include "Database.hpp"
#include <iostream>

#include "Score.hpp"
#include "../../backend/objects/ItemFactory.hpp"

namespace frontend {
    Database::Database(std::string path): path_(path), connection_(nullptr) {
        if (sqlite3_open_v2("kerkersendraken.db", &connection_, SQLITE_OPEN_READWRITE, nullptr) != SQLITE_OK) {
            sqlite3_close_v2(connection_);
            std::cerr << "error opening database file\n";
        }


    }

    Database::~Database() {
        sqlite3_close_v2(connection_);
    }

    std::vector<std::unique_ptr<backend::Location>> Database::GetLocations() {
        std::string query {"SELECT naam, beschrijving from Locaties"};
        sqlite3_stmt *statement {nullptr};
        auto result = sqlite3_prepare_v2(connection_, query.c_str(), -1, &statement, nullptr);
        if (result != SQLITE_OK) {
            throw std::runtime_error("failed to prepare statement");
        }

        std::vector<std::unique_ptr<backend::Location>> locations;
        while ((result = sqlite3_step(statement)) == SQLITE_ROW) {
            auto name = helpers::TypoTrap(reinterpret_cast<const char*>(sqlite3_column_text(statement, 0)));
            auto i = sqlite3_errmsg(connection_);
            auto description = helpers::TypoTrap(reinterpret_cast<const char*>(sqlite3_column_text(statement, 1)));
            locations.emplace_back(std::make_unique<backend::Location>(name, description));
        }
        if (result != SQLITE_DONE) {
            throw std::runtime_error("failed to prepare statement");
        }

        sqlite3_finalize(statement);

        return locations;
    }

    std::vector<backend::ItemTypeDTO> Database::GetItems() {
        std::string query {"SELECT naam, omschrijving, type, minimumwaarde, maximumwaarde, bescherming from Objecten"};
        sqlite3_stmt *statement {nullptr};
        auto result = sqlite3_prepare_v2(connection_, query.c_str(), -1, &statement, nullptr);
        if (result != SQLITE_OK) {
            throw std::runtime_error("failed to prepare statement");
        }

        backend::ItemFactory factory;
        std::vector<backend::ItemTypeDTO> items;
        while ((result = sqlite3_step(statement)) == SQLITE_ROW) {
            auto name = std::string(reinterpret_cast<const char*>(sqlite3_column_text(statement, 0)));
            auto description = std::string(reinterpret_cast<const char*>(sqlite3_column_text(statement, 1)));
            auto type = std::string(reinterpret_cast<const char*>(sqlite3_column_text(statement, 2)));
            auto minimum_value = sqlite3_column_int(statement, 3);
            auto maximum_value = sqlite3_column_int(statement, 4);
            auto protection = sqlite3_column_int(statement, 5);
            //TODO: add randomness and move to random level creator
            items.push_back(backend::ItemTypeDTO{
                name,
                description,
                type,
                minimum_value,
                maximum_value,
                protection
            });
        }
        if (result != SQLITE_DONE) {
            throw std::runtime_error("failed to prepare statement");
        }

        sqlite3_finalize(statement);

        return items;
    }

    backend::ItemTypeDTO Database::GetItem(const std::string &name) {
        std::string query {"SELECT naam, omschrijving, type, minimumwaarde, maximumwaarde, bescherming from Objecten WHERE naam = "};
        query += "'" + name + "'";
        sqlite3_stmt *statement {nullptr};
        auto result = sqlite3_prepare_v2(connection_, query.c_str(), -1, &statement, nullptr);
        if (result != SQLITE_OK) {
            throw std::runtime_error("failed to prepare statement");
        }

        backend::ItemTypeDTO item;
        if ((result = sqlite3_step(statement)) == SQLITE_ROW) {
            auto name = std::string(reinterpret_cast<const char*>(sqlite3_column_text(statement, 0)));
            auto description = std::string(reinterpret_cast<const char*>(sqlite3_column_text(statement, 1)));
            auto type = std::string(reinterpret_cast<const char*>(sqlite3_column_text(statement, 2)));
            auto minimum_value = sqlite3_column_int(statement, 3);
            auto maximum_value = sqlite3_column_int(statement, 4);
            auto protection = sqlite3_column_int(statement, 5);
            item = backend::ItemTypeDTO{
                name,
                description,
                type,
                minimum_value,
                maximum_value,
                protection
            };
        }
        else {
            throw std::runtime_error("failed to prepare statement");
        }

        sqlite3_finalize(statement);

        return item;
    }

    backend::EnemyTypeDTO Database::GetEnemy(const std::string &name) {
        std::string query {"SELECT naam, omschrijving, minimumobjecten, maximumobjecten, levenspunten, aanvalskans, minimumschade, maximumschade from Vijanden WHERE naam = "};
        query += "'" + name + "'";
        sqlite3_stmt *statement {nullptr};
        auto result = sqlite3_prepare_v2(connection_, query.c_str(), -1, &statement, nullptr);
        if (result != SQLITE_OK) {
            throw std::runtime_error(sqlite3_errmsg(connection_));
        }

        backend::EnemyTypeDTO enemy;
        if ((result = sqlite3_step(statement)) == SQLITE_ROW) {
            auto name = std::string(reinterpret_cast<const char*>(sqlite3_column_text(statement, 0)));
            auto description = std::string(reinterpret_cast<const char*>(sqlite3_column_text(statement, 1)));
            auto minimum_items = sqlite3_column_int(statement, 2);
            auto maximum_items = sqlite3_column_int(statement, 3);
            auto minimum_damage = sqlite3_column_int(statement, 6);
            auto maximum_damage = sqlite3_column_int(statement, 7);
            auto hitpoints = sqlite3_column_int(statement, 4);
            auto attack_chance = sqlite3_column_int(statement, 5);
            enemy = backend::EnemyTypeDTO{
                name,
                description,
                minimum_items,
                maximum_items,
                hitpoints,
                attack_chance,
                minimum_damage,
                maximum_damage,
            };
        }
        else {
            throw std::runtime_error("failed to prepare statement");
        }

        sqlite3_finalize(statement);

        return enemy;
    }

    void Database::AddScore(Score score) {
        std::string query {"INSERT INTO Leaderboard (naam, goudstukken) VALUES ('"};
        query += score.name + "', " + std::to_string(score.score) + ");";
        sqlite3_stmt *statement {nullptr};
        auto result = sqlite3_prepare_v2(connection_, query.c_str(), -1, &statement, nullptr);
        if (result != SQLITE_OK) {
            throw std::runtime_error("failed to prepare statement");
        }

        if ((result = sqlite3_step(statement)) != SQLITE_DONE) {
            throw std::runtime_error(sqlite3_errmsg(connection_));
        }

        sqlite3_finalize(statement);
    }
} // frontend