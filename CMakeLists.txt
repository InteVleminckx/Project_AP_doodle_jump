cmake_minimum_required(VERSION 3.16.2)
project(doodle_jump)

# Extend the CMake module path to find the FindSFML.cmake
# file in {project root}/cmake/Modules
SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake/Modules/")

# Look for SFML >= 2.0, with the specific subcomponents listed below
FIND_PACKAGE(SFML 2 COMPONENTS system window graphics)

# The source files to compile
SET(SRC source/main.cpp source/Player.cpp source/Player.h source/Platform.cpp source/Platform.h source/Bonus.cpp source/Bonus.h source/BG_Tile.cpp source/BG_Tile.h source/Entity.cpp source/Entity.h)

# Add include dirs for SFML
# (The SFML_INCLUDE_DIR variable is defined by FindSFML.cmake, if SFML was found)
INCLUDE_DIRECTORIES(${SFML_INCLUDE_DIR})

# The program we're compiling with the sources set above
ADD_EXECUTABLE(doodle_jump ${SRC})

# Link target to SFML libs
# (The SFML_LIBRARIES variable is defined by FindSFML.cmake, if SFML was found)
TARGET_LINK_LIBRARIES(doodle_jump ${SFML_LIBRARIES})

INSTALL(TARGETS doodle_jump DESTINATION ${PROJECT_SOURCE_DIR}/bin)