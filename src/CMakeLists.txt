cmake_minimum_required(VERSION 3.26)
project(karculatqr)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(karculatqr main.cpp MainWindow.cpp)
target_link_libraries(karculatqr
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        )

