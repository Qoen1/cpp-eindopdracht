//
// Created by koenv on 26/01/2025.
//

#ifndef GODMODEINPUTHANDLER_HPP
#define GODMODEINPUTHANDLER_HPP
#include "BaseInputHandler.hpp"

namespace frontend {
    class Player;

    class GodmodeInputHandler: public BaseInputHandler {
    public:
        GodmodeInputHandler(const std::string &inputCommand, Player &player, std::ostream &output);

    protected:
        void Handle(const std::vector<std::string> &arguments) const override;

    private:
    Player& player_;
    std::ostream &output;
};

} // frontend

#endif //GODMODEINPUTHANDLER_HPP
