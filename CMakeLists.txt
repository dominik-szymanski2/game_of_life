cmake_minimum_required(VERSION 3.10)
project(life)

set(CMAKE_CXX_STANDARD 20)

include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_library(conway_game SHARED ConwayGame/ConwayCell.cpp ConwayGame/CellArray2D.hpp ConwayGame/CellArray2D.cpp ConwayGame/ConwayLoader.cpp ConwayGame/ConwayLoader.hpp)
target_include_directories(conway_game PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}/ConwayGame")

# qt display implementation
add_subdirectory("QtDisplay/")

# qt game interface
add_subdirectory("QtGameInterface/")

add_executable(life main.cpp Cell.hpp GameEngine.cpp GameEngine.hpp CellArray.hpp Display.hpp Canvas.hpp Loader.hpp)
target_include_directories(life PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}/QtDisplay")

target_link_libraries(${PROJECT_NAME} conway_game QtDisplay QtGameInterface)