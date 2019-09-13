cmake_minimum_required(VERSION 3.14)
project(Qt_NetCap)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

if (WIN32)
    set(CMAKE_PREFIX_PATH "C:\\Qt\\5.13.1\\msvc2017_64\\lib\\cmake")
endif (WIN32)

find_package(Qt5 5.9.1 COMPONENTS Core Widgets Gui Qml Quick REQUIRED)

add_executable(Qt_NetCap main.cpp backend.h backend.cpp main.qml qml.qrc)

target_link_libraries(Qt_NetCap
        Qt5::Core
        Qt5::Widgets
        Qt5::Gui
        Qt5::Qml
        Qt5::Quick)
