//
// Created by fikkie on 28/10/24.
//

#ifndef LOOKINROOMCOMMAND_HPP
#define LOOKINROOMCOMMAND_HPP
#include "ICommand.hpp"
#include "../../backend/location/Location.hpp"

namespace frontend {

class LookInRoomCommand : ICommand {
private:
    backend::Location& location;
    std::ostream& output_;
public:
    LookInRoomCommand(backend::Location& passedLocation, std::ostream& output);
    void Execute() override;
};

} // frontend

#endif //LOOKINROOMCOMMAND_HPP
