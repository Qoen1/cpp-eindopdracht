#include "backend/location/Location.hpp"
#include "backend/objects/Weapon.hpp"
#include "frontend/commands/LookInRoomCommand.hpp"
#include "frontend/configReader/RandomMapGenerator.hpp"


int main()
{
    auto generator = RandomMapGenerator();
    auto locations = std::make_unique<std::vector<backend::Location*>>(*generator.Generate());
    auto* ree {new backend::Weapon()};
    locations->at(0)->AddVisibleItem(ree);
    auto* command = new frontend::LookInRoomCommand(*locations->at(0));
    command->Execute();
    return 0;
}
