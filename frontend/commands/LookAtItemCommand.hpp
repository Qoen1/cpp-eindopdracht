//
// Created by koenv on 31/10/2024.
//

#ifndef LOOKATITEMCOMMAND_HPP
#define LOOKATITEMCOMMAND_HPP
#include "ICommand.hpp"
#include "../../backend/objects/Item.hpp"

namespace frontend {

class LookAtItemCommand : public ICommand {
public:
    LookAtItemCommand(const backend::Item& item);
    void Execute() override;
private:
    const backend::Item& item_;
};

} // frontend

#endif //LOOKATITEMCOMMAND_HPP
