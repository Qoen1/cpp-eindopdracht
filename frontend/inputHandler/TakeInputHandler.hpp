//
// Created by koenv on 24/01/2025.
//

#ifndef TAKEINPUTHANDLER_HPP
#define TAKEINPUTHANDLER_HPP
#include "BaseInputHandler.hpp"

namespace frontend {
    class Player;

    class TakeInputHandler: public BaseInputHandler {
public:
    explicit TakeInputHandler(const std::string &inputCommand, Player &player)
        : BaseInputHandler(inputCommand), player_(player) {
    }

protected:
    void Handle(const std::vector<std::string> &arguments) const override;

private:
    Player &player_;
};

} // frontend

#endif //TAKEINPUTHANDLER_HPP
