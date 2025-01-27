cmake_minimum_required(VERSION 3.20)
project(cpp_eindopdracht)

set(CMAKE_CXX_STANDARD 20)

find_package(SQLite3 REQUIRED)

add_executable(cpp_eindopdracht main.cpp
        external/pugixml.hpp
        external/pugixml.cpp
        backend/objects/Item.hpp
        frontend/player/Player.cpp
        frontend/player/Player.hpp
        helpers/BigBrainPointer.hpp
        backend/objects/Gold.cpp
        backend/objects/Gold.hpp
        backend/objects/Armor.cpp
        backend/objects/Armor.hpp
        backend/objects/Weapon.cpp
        backend/objects/Weapon.hpp
        backend/location/Location.cpp
        backend/location/Location.hpp
        backend/objects/ItemFactory.cpp
        backend/objects/ItemFactory.hpp
        backend/location/LocationFactory.cpp
        backend/location/LocationFactory.hpp
        backend/enemy/Enemy.cpp
        backend/enemy/Enemy.hpp
        backend/enemy/EnemyFactory.cpp
        backend/enemy/EnemyFactory.hpp
        helpers/TypoTrap.hpp
        helpers/DynamicDoodad.hpp
        frontend/player/IPlayerState.hpp
        frontend/player/GodState.cpp
        frontend/player/GodState.hpp
        frontend/player/RegularState.cpp
        frontend/player/RegularState.hpp
        frontend/configReader/IMapGenerator.hpp
        frontend/configReader/FileMapGenerator.cpp
        frontend/configReader/FileMapGenerator.hpp
        frontend/configReader/RandomMapGenerator.cpp
        frontend/configReader/RandomMapGenerator.hpp
        frontend/commands/ICommand.hpp
        frontend/commands/LookInRoomCommand.cpp
        frontend/commands/LookInRoomCommand.hpp
        frontend/inputHandler/BaseInputHandler.hpp
        frontend/inputHandler/BaseInputHandler.cpp
        frontend/inputHandler/BaseInputHandler.hpp
        frontend/inputHandler/LookInputHandler.cpp
        frontend/inputHandler/LookInputHandler.hpp
        frontend/commands/LookAtPlayerCommand.cpp
        frontend/commands/LookAtPlayerCommand.hpp
        frontend/commands/LookAtItemCommand.cpp
        frontend/commands/LookAtItemCommand.hpp
        frontend/commands/LookAtEnemyCommand.cpp
        frontend/commands/LookAtEnemyCommand.hpp
        frontend/commands/SearchLocationCommand.cpp
        frontend/commands/SearchLocationCommand.hpp
        frontend/inputHandler/SearchInputHandler.cpp
        frontend/inputHandler/SearchInputHandler.hpp
        backend/Direction.hpp
        frontend/commands/MoveCommand.cpp
        frontend/commands/MoveCommand.hpp
        frontend/inputHandler/MoveInputHandler.cpp
        frontend/inputHandler/MoveInputHandler.hpp
        backend/Door.cpp
        backend/Door.hpp
        helpers/OwningDynamicDoodad.hpp
        frontend/database/Database.cpp
        frontend/database/Database.hpp
        frontend/inputHandler/QuitInputHandler.cpp
        frontend/inputHandler/QuitInputHandler.hpp
        frontend/inputHandler/InvalidInputHandler.cpp
        frontend/inputHandler/InvalidInputHandler.hpp
        backend/objects/Item.cpp
        frontend/inputHandler/TakeInputHandler.cpp
        frontend/inputHandler/TakeInputHandler.hpp
        frontend/inputHandler/PlaceInputHandler.cpp
        frontend/inputHandler/PlaceInputHandler.hpp
        frontend/inputHandler/WearInputHandler.cpp
        frontend/inputHandler/WearInputHandler.hpp
        frontend/commands/AttackCommand.cpp
        frontend/commands/AttackCommand.hpp
        frontend/inputHandler/AttackInputHandler.cpp
        frontend/inputHandler/AttackInputHandler.hpp
        frontend/inputHandler/WaitInputHandler.cpp
        frontend/inputHandler/WaitInputHandler.hpp
        backend/objects/consumable/Consumable.cpp
        backend/objects/consumable/Consumable.hpp
        backend/objects/consumable/ExperienceBoostConsumable.cpp
        backend/objects/consumable/ExperienceBoostConsumable.hpp
        backend/objects/consumable/HealthBoostConsumable.cpp
        backend/objects/consumable/HealthBoostConsumable.hpp
        backend/objects/consumable/TeleportationConsumable.cpp
        backend/objects/consumable/TeleportationConsumable.hpp
        frontend/commands/ConsumeItemCommand.cpp
        frontend/commands/ConsumeItemCommand.hpp
        frontend/inputHandler/ConsumeInputHandler.cpp
        frontend/inputHandler/ConsumeInputHandler.hpp
        frontend/inputHandler/HelpInputManager.cpp
        frontend/inputHandler/HelpInputManager.hpp
        frontend/inputHandler/GodmodeInputHandler.cpp
        frontend/inputHandler/GodmodeInputHandler.hpp
        backend/Game.cpp
        backend/Game.hpp
        frontend/commands/EnemyTurnCommand.cpp
        frontend/commands/EnemyTurnCommand.hpp
        frontend/database/Score.hpp
        helpers/Logger.hpp
)

target_link_libraries(cpp_eindopdracht SQLite::SQLite3)

add_custom_command(TARGET cpp_eindopdracht POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        "${CMAKE_CURRENT_SOURCE_DIR}/kerkersendraken.db"
        "${CMAKE_CURRENT_BINARY_DIR}/kerkersendraken.db")
add_custom_command(TARGET cpp_eindopdracht POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        "${CMAKE_CURRENT_SOURCE_DIR}/kasteelruine.xml"
        "${CMAKE_CURRENT_BINARY_DIR}/kasteelruine.xml")
