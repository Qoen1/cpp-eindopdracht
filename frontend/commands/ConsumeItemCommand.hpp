//
// Created by koenv on 26/01/2025.
//

#ifndef CONSUMEITEMCOMMAND_HPP
#define CONSUMEITEMCOMMAND_HPP
#include <string>

#include "ICommand.hpp"

namespace frontend {
    class Player;

    class ConsumeItemCommand: ICommand {
public:
        ConsumeItemCommand(Player &player, const std::string &item_name, std::ostream& output);

        void Execute() override;
private:
    Player& player_;
    std::string item_name_;
    std::ostream& output_;
};

} // frontend

#endif //CONSUMEITEMCOMMAND_HPP
