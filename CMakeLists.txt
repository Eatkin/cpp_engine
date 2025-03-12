cmake_minimum_required(VERSION 3.10.0)
project(Sokoban VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)

# Add include directory so headers can be found
include_directories(${CMAKE_SOURCE_DIR}/include)

# Find all .cpp files in src/ and store them in a variable
file(GLOB_RECURSE SOURCES ${CMAKE_SOURCE_DIR}/src/*.cpp)

# Create the executable from all source files
add_executable(Sokoban ${SOURCES})

# Link SDL2 (assuming you've found it earlier in the file)
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
target_link_libraries(Sokoban ${SDL2_LIBRARIES})
