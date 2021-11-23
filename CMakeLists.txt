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
include_directories(src/Logic_libary src/Game_Representation)
add_subdirectory(src/Logic_libary)
add_subdirectory(src/Game_Representation)


# Add include dirs for SFML
# (The SFML_INCLUDE_DIR variable is defined by FindSFML.cmake, if SFML was found)
INCLUDE_DIRECTORIES(${SFML_INCLUDE_DIR})

# The program we're compiling with the sources set above
ADD_EXECUTABLE(doodle_jump src/main.cpp src/Exceptions.cpp)

target_link_libraries(doodle_jump representation logic)

# Link target to SFML libs
# (The SFML_LIBRARIES variable is defined by FindSFML.cmake, if SFML was found)
TARGET_LINK_LIBRARIES(doodle_jump ${SFML_LIBRARIES})

INSTALL(TARGETS doodle_jump DESTINATION ${PROJECT_SOURCE_DIR}/bin)
