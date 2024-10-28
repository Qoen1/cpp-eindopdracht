cmake_minimum_required(VERSION 3.29)
project(cpp_eindopdracht)

set(CMAKE_CXX_STANDARD 20)

add_executable(cpp_eindopdracht main.cpp
        backend/objects/Item.hpp
        frontend/player/Player.cpp
        frontend/player/Player.hpp
        helpers/BigBrainPointer.hpp
        backend/objects/Gold.cpp
        backend/objects/Gold.hpp
        backend/objects/Consumable.cpp
        backend/objects/Consumable.hpp
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
        frontend/commands/LookInRoomCommand.hpp)
