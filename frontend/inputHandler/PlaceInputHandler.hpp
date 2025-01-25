//
// Created by koenv on 25/01/2025.
//

#ifndef PLACEINPUTHANDLER_HPP
#define PLACEINPUTHANDLER_HPP
#include "BaseInputHandler.hpp"

namespace frontend {
    class Player;

    class PlaceInputHandler: public BaseInputHandler{
public:
    explicit PlaceInputHandler(const std::string &inputCommand, Player& player)
        : BaseInputHandler(inputCommand), player_(player) {
    }

protected:
    void Handle(const std::vector<std::string> &arguments) const override;

private:
    Player& player_;
};

} // frontend

#endif //PLACEINPUTHANDLER_HPP
