//
// Created by fikkie on 28/10/24.
//

#ifndef SEARCHCOMMAND_HPP
#define SEARCHCOMMAND_HPP
#include "ICommand.hpp"

namespace frontend {

class SearchCommand : public ICommand{
public:
    SearchCommand();
    void Execute() override;
};

} // frontend

#endif //SEARCHCOMMAND_HPP
