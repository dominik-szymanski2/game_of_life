cmake_minimum_required(VERSION 3.10)
project(QtGameInterface)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(QT_PATH /home/dominik/Qt/5.15.0/gcc_64/)
set(MAIN_INCLUDES /home/dominik/Documents/projects/game_of_life/)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

find_package(Qt5 COMPONENTS Widgets REQUIRED PATHS /home/dominik/Qt/5.15.0/gcc_64/)

add_compile_options(-fPIC)

add_library(QtGameInterface GameInterface.hpp GameInterface.cpp)

target_include_directories(QtGameInterface PUBLIC /home/dominik/Qt/5.15.0/gcc_64/include/ ${MAIN_INCLUDES})
target_link_libraries(QtGameInterface Qt5::Widgets)