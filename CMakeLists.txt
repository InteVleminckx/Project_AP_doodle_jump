cmake_minimum_required(VERSION 3.16.2)
project(doodle_jump)

find_package(Doxygen)
if(DOXYGEN_FOUND)
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in
            ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY)
    add_custom_target(doc ${DOXYGEN_EXECUTABLE}
            ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile WORKING_DIRECTORY
            ${CMAKE_CURRENT_BINARY_DIR} COMMENT "Generating API
documentation" VERBATIM)
endif(DOXYGEN_FOUND)


# Extend the CMake module path to find the FindSFML.cmake
# file in {project root}/cmake/Modules
SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake/Modules/")

# Look for SFML >= 2.0, with the specific subcomponents listed below
FIND_PACKAGE(SFML 2 COMPONENTS system window graphics)

# The src files to compile
SET(SRC src/main.cpp
        src/Player_L.cpp
        src/Player_L.h
        src/Platform_L.cpp
        src/Platform_L.h
        src/Bonus_L.cpp
        src/Bonus_L.h
        src/BG_Tile_L.cpp
        src/BG_Tile_L.h
        src/Entity_Model.cpp
        src/Entity_Model.h
        src/Subject.cpp
        src/Subject.h
        src/Observer.cpp
        src/Observer.h
        )

# Add include dirs for SFML
# (The SFML_INCLUDE_DIR variable is defined by FindSFML.cmake, if SFML was found)
INCLUDE_DIRECTORIES(${SFML_INCLUDE_DIR})

# The program we're compiling with the sources set above
ADD_EXECUTABLE(doodle_jump ${SRC})

# Link target to SFML libs
# (The SFML_LIBRARIES variable is defined by FindSFML.cmake, if SFML was found)
TARGET_LINK_LIBRARIES(doodle_jump ${SFML_LIBRARIES})

INSTALL(TARGETS doodle_jump DESTINATION ${PROJECT_SOURCE_DIR}/bin)
