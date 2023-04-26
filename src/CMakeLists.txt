cmake_minimum_required(VERSION 3.24)
project(karculatqr)

set(CMAKE_OSX_ARCHITECTURES "x86_64")

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Test targets
enable_testing()

include(GoogleTest)

add_library(MathLibrary MathLibrary.cpp MathLibrary.h MathLibraryExceptions.h MathLibraryExceptions.cpp)

add_executable(MathLibraryTest tests/MathLibraryTest.cpp)

target_link_libraries(MathLibraryTest gtest_main MathLibrary)

add_test(NAME MathLibraryTest COMMAND MathLibraryTest)

add_executable(stddev stddev.cpp)
target_link_libraries(stddev MathLibrary)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)


set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(karculatqr main.cpp MainWindow.cpp Interface.cpp)
target_link_libraries(karculatqr
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
		MathLibrary
		)
