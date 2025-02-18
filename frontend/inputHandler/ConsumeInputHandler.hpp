//
// Created by koenv on 26/01/2025.
//

#ifndef CONSUMEINPUTHANDLER_HPP
#define CONSUMEINPUTHANDLER_HPP
#include "BaseInputHandler.hpp"

namespace frontend {
    class Player;

    class ConsumeInputHandler: public BaseInputHandler {
    public:
        ConsumeInputHandler(const std::string &inputCommand, Player &player, std::ostream &output);

    protected:
        void Handle(const std::vector<std::string> &arguments) const override;

    private:
    Player& player_;
    std::ostream &output_;

};

} // frontend

#endif //CONSUMEINPUTHANDLER_HPP
