cmake_minimum_required(VERSION 3.30.2)
project(roguelike LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

add_executable(main
    src/main.cpp
    src/visualizer/Visualizer.cpp
    src/common/random/Random.cpp
    src/common/room/Room.cpp
    src/common/vector2/Vector2.cpp
    src/common/container/Container.cpp
    src/common/tree/Tree.cpp
    src/algorithms/bspTrees/BSPDrawer.cpp)

target_link_libraries(main PRIVATE sfml-graphics)
target_compile_features(main PRIVATE cxx_std_17)
