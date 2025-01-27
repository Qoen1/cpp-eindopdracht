#include <iostream>

#include "helpers/BigBrainPointer.hpp"
#include "helpers/DynamicDoodad.hpp"
#include "helpers/TypoTrap.hpp"

#include "backend/location/Location.hpp"
#include "backend/objects/Weapon.hpp"
#include "frontend/commands/LookAtItemCommand.hpp"
#include "frontend/commands/LookAtPlayerCommand.hpp"
#include "frontend/commands/LookInRoomCommand.hpp"
#include "frontend/configReader/RandomMapGenerator.hpp"
#include "frontend/inputHandler/LookInputHandler.hpp"
#include "frontend/inputHandler/MoveInputHandler.hpp"
#include "frontend/inputHandler/SearchInputHandler.hpp"
#include <memory>
#include <vector>
#include <sqlite3.h>

#include "backend/Game.hpp"
#include "backend/objects/consumable/Consumable.hpp"
#include "backend/objects/Gold.hpp"
#include "frontend/commands/EnemyTurnCommand.hpp"
#include "frontend/configReader/FileMapGenerator.hpp"
#include "frontend/database/Database.hpp"
#include "frontend/database/Score.hpp"
#include "frontend/inputHandler/AttackInputHandler.hpp"
#include "frontend/inputHandler/ConsumeInputHandler.hpp"
#include "frontend/inputHandler/GodmodeInputHandler.hpp"
#include "frontend/inputHandler/HelpInputManager.hpp"
#include "frontend/inputHandler/InvalidInputHandler.hpp"
#include "frontend/inputHandler/PlaceInputHandler.hpp"
#include "frontend/inputHandler/QuitInputHandler.hpp"
#include "frontend/inputHandler/TakeInputHandler.hpp"
#include "frontend/inputHandler/WaitInputHandler.hpp"
#include "frontend/inputHandler/WearInputHandler.hpp"

#define MAX_INPUT_LENGTH 100

bool playing {true};

int main()
{
    bool retrying {true};
    while (retrying) {
        std::shared_ptr<frontend::Database> database = std::make_shared<frontend::Database>("kerkersendraken.db");

        auto file_reader = FileMapGenerator("kasteelruine.xml", database);
        auto random_reader = RandomMapGenerator(database);

        auto locations = helpers::OwningDynamicDoodad<backend::Location>();
        {
            auto locations_vector = random_reader.Generate();
            for (auto i = 0; i < locations_vector.size(); ++i) {
                locations.push_back(std::move(locations_vector.at(i)).release());
            }
        }
        auto game = std::make_unique<backend::Game>(std::move(locations));


        auto player = std::make_unique<frontend::Player>(game->GetLocation(0));
        player->AddItemToInventory(std::make_unique<backend::Weapon>("wooden sword", "a wooden sword", 25));
        player->UseItemFromInventory("wooden sword");

        std::unique_ptr<frontend::ICommand> move_enemies_command = std::make_unique<frontend::EnemyTurnCommand>(*game, *player);
        std::vector<frontend::BaseInputHandler*> inputHandlers = {
            new frontend::InvalidInputHandler(), //needs to be last because it always consumes the command.
            new frontend::LookInputHandler("look",*player),
            new frontend::SearchInputHandler("search", *player, *move_enemies_command),
            new frontend::MoveInputHandler("move", *player, *move_enemies_command),
            new frontend::TakeInputHandler("take", *player),
            new frontend::PlaceInputHandler("place", *player),
            new frontend::WearInputHandler("wear", *player, *move_enemies_command),
            new frontend::AttackInputHandler("attack", *player, *move_enemies_command),
            new frontend::WaitInputHandler("wait", *move_enemies_command),
            new frontend::ConsumeInputHandler("consume", *player),
            new frontend::GodmodeInputHandler("godmode", *player),
            new frontend::HelpInputManager("help"),
            new frontend::QuitInputHandler("quit", playing)
        };
        std::unique_ptr<frontend::BaseInputHandler> inputHandler = nullptr;
        for(auto handler : inputHandlers) {
            if(inputHandler != nullptr) {
                handler->SetNextHandler(*inputHandler.release());
            }
            inputHandler = std::unique_ptr<frontend::BaseInputHandler>(handler);
        }


        frontend::LookInRoomCommand(*player->currentLocation).Execute();

        while (playing) {
            char result[MAX_INPUT_LENGTH];
            std::cin.getline(result, MAX_INPUT_LENGTH);
            std::string line{result};
            std::vector<std::string> parts;

            auto space = line.find(' ');
            bool go_on{true};
            while (go_on) {
                parts.push_back(line.substr(0, space));
                line = line.substr(space + 1);
                go_on = space != std::string::npos;
                space = line.find(' ');
            }
            auto command = parts[0];
            parts.erase(parts.begin());
            inputHandler->Handle(command, parts);
            if (player->GetHitpoints() <= 0) {
                playing = false;
            }
        }

        std::cout << "The end. Your score was: " << player->GetCoinCount() << " ";
        char result[MAX_INPUT_LENGTH];
        result[0] = '\0';

        while (strlen(result) == 0 || (result[0] != 'y' && result[0] != 'n')) {
            std::cout << "save this to the leaderboard? (y/n)" << std::endl;
            std::cin.getline(result, MAX_INPUT_LENGTH);
            if (result[0] == 'y') {
                char name_arr[MAX_INPUT_LENGTH];
                name_arr[0] = '\0';
                while (strlen(name_arr) == 0) {
                    std::cout << "please enter a name for the leaderboard: ";
                    std::cin.getline(name_arr, MAX_INPUT_LENGTH);
                }

                std::string name{name_arr};
                database->AddScore(Score{name, player->GetCoinCount()});
            }
        }

        char retry_result[MAX_INPUT_LENGTH];
        retry_result[0] = '\0';
        while (strlen(retry_result) == 0 || (retry_result[0] != 'y' && retry_result[0] != 'n')) {
            std::cout << "retry? (y/n)" << std::endl;
            std::cin.getline(retry_result, MAX_INPUT_LENGTH);
        }
        retrying = retry_result[0] == 'y';
        playing = true;
    }


    return 0;
}
