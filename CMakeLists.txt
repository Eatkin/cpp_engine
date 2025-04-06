cmake_minimum_required(VERSION 3.10.0)
project(Sokoban VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)

# Add include directory so headers can be found
include_directories(${CMAKE_SOURCE_DIR}/include)

# Find all .cpp files in src/ and store them in a variable
file(GLOB_RECURSE SOURCES ${CMAKE_SOURCE_DIR}/src/*.cpp ${CMAKE_SOURCE_DIR}/src/objects/*.cpp)

# Create the executable from all source files
add_executable(Sokoban ${SOURCES})

# Link SDL2
find_package(PkgConfig REQUIRED)
pkg_check_modules(SDL2 REQUIRED sdl2)
pkg_check_modules(SDL2_IMAGE REQUIRED SDL2_image)
include_directories(${SDL2_INCLUDE_DIRS})
target_link_libraries(
  Sokoban ${SDL2_LIBRARIES}
  ${SDL2_IMAGE_LIBRARIES}
)
