//
// Created by koenv on 25/01/2025.
//

#ifndef ATTACKINPUTHANDLER_HPP
#define ATTACKINPUTHANDLER_HPP
#include "BaseInputHandler.hpp"

namespace frontend {
    class Player;

    class AttackInputHandler: public BaseInputHandler {
    public:
        AttackInputHandler(const std::string &inputCommand, Player &player);

    protected:
        void Handle(const std::vector<std::string> &arguments) const override;

    private:
    Player& player_;
};

} // frontend

#endif //ATTACKINPUTHANDLER_HPP
