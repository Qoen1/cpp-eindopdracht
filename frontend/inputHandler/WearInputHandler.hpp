//
// Created by koenv on 25/01/2025.
//

#ifndef WEARINPUTHANDLER_HPP
#define WEARINPUTHANDLER_HPP
#include "BaseInputHandler.hpp"

namespace frontend {
    class Player;

    class WearInputHandler: public BaseInputHandler{
public:
    explicit WearInputHandler(const std::string &inputCommand, Player& player);

protected:
    void Handle(const std::vector<std::string> &arguments) const override;

private:
    Player& player_;
};

} // frontend

#endif //WEARINPUTHANDLER_HPP
