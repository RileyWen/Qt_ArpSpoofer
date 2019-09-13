cmake_minimum_required(VERSION 3.14)
project(Qt_NetCap)

if (UNIX)
    set(CMAKE_PREFIX_PATH "/home/rileywen/Qt/5.13.1/gcc_64/lib/cmake")
endif (UNIX)

if (WIN32)
    set(CMAKE_PREFIX_PATH "C:\\Qt\\5.13.1\\msvc2017_64\\lib\\cmake")
endif (WIN32)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5 COMPONENTS Core Widgets Gui Qml Quick REQUIRED)

add_executable(Qt_NetCap Qt_GUI/sources/main.cpp Qt_GUI/headers/DropRateSlider.h
        Qt_GUI/sources/DropRateSlider.cpp Qt_GUI/resources/main.qml Qt_GUI/resources/qml.qrc Qt_GUI/sources/TextListModel.cpp Qt_GUI/headers/TextListModel.h Qt_GUI/headers/SharedVariables.h)

target_link_libraries(Qt_NetCap
        Qt5::Core
        Qt5::Widgets
        Qt5::Gui
        Qt5::Qml
        Qt5::Quick)
