//
// Created by koenv on 31/10/2024.
//

#ifndef SEARCHLOCATIONCOMMAND_HPP
#define SEARCHLOCATIONCOMMAND_HPP
#include "ICommand.hpp"
#include "../../backend/location/Location.hpp"


namespace frontend {

class SearchLocationCommand : public ICommand{
public:
    SearchLocationCommand(backend::Location& location, std::ostream& output);
    void Execute() override;
private:
    backend::Location& location_;
    std::ostream& output_;
};

}

#endif //SEARCHLOCATIONCOMMAND_HPP
