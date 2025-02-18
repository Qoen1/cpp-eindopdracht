//
// Created by koenv on 25/01/2025.
//

#ifndef WEARINPUTHANDLER_HPP
#define WEARINPUTHANDLER_HPP
#include "BaseInputHandler.hpp"

namespace frontend {
    class ICommand;
    class Player;

    class WearInputHandler: public BaseInputHandler{
public:
    explicit WearInputHandler(const std::string &inputCommand, Player& player, ICommand &move_enemies_command, std::ostream& output);

protected:
    void Handle(const std::vector<std::string> &arguments) const override;

private:
    Player& player_;
    ICommand& move_enemies_command_;
    std::ostream& output_;
};

} // frontend

#endif //WEARINPUTHANDLER_HPP
