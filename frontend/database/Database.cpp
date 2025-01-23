#include "Database.hpp"
#include <iostream>

namespace frontend {
    Database::Database(std::string path): path_(path), connection_(nullptr) {
        if (sqlite3_open_v2("kerkersendraken.db", &connection_, SQLITE_OPEN_READONLY, nullptr) != SQLITE_OK) {
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
            auto* name = new helpers::TypoTrap(reinterpret_cast<const char*>(sqlite3_column_text(statement, 0)));
            auto i = sqlite3_errmsg(connection_);
            auto* description = new helpers::TypoTrap(reinterpret_cast<const char*>(sqlite3_column_text(statement, 1)));
            locations.emplace_back(std::make_unique<backend::Location>(name, description));
        }
        if (result != SQLITE_DONE) {
            throw std::runtime_error("failed to prepare statement");
        }

        sqlite3_finalize(statement);

        return locations;
    }
} // frontend