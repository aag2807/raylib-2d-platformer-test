cmake_minimum_required(VERSION 3.28)

project(SimplePlatformer)

set(CMAKE_CXX_STANDARD 17)

find_package(raylib REQUIRED)

add_executable(SimplePlatformer main.cpp
        src/Renderable.h
        src/World.cpp
        src/World.h
        src/Player.cpp
        src/Player.h
        src/Collectable.h
        src/Coin.cpp
        src/Coin.h
        src/CommandQueue.cpp
        src/CommandQueue.h
        src/ScoreManager.cpp
        src/ScoreManager.h)

target_link_libraries(SimplePlatformer raylib)