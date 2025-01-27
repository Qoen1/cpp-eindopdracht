

#ifndef INVALIDINPUTHANDLER_HPP
#define INVALIDINPUTHANDLER_HPP
#include "BaseInputHandler.hpp"

namespace frontend {

class InvalidInputHandler: public BaseInputHandler {
public:
    InvalidInputHandler(std::ostream& output);

    void Handle(const std::string& inputCommand, const std::vector<std::string>& arguments) const override;

protected:
    void Handle(const std::vector<std::string>& arguments) const override;
private:
    std::ostream& output_;
};

} // frontend

#endif //INVALIDINPUTHANDLER_HPP
