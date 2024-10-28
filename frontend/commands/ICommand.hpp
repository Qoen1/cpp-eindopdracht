//
// Created by fikkie on 28/10/24.
//

#ifndef ICOMMAND_HPP
#define ICOMMAND_HPP

namespace frontend {

class ICommand {
public:
    virtual void Execute() = 0;

};

} // frontend

#endif //ICOMMAND_HPP
