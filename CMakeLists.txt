cmake_minimum_required(VERSION 3.29)
project(cpp_eindopdracht)

set(CMAKE_CXX_STANDARD 20)

add_executable(cpp_eindopdracht main.cpp
        backend/objects/Item.cpp
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
        backend/enemy/EnemyFactory.hpp)
