cmake_minimum_required(VERSION 3.22)
project(snake_game LANGUAGES CXX)

# Use C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD_EXTENSIONS OFF)

# Find threads
find_package(Threads REQUIRED)

add_executable(snake_game
    src/main.cpp
    src/snake.cpp
)

target_include_directories(snake_game
    PRIVATE
        ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(snake_game 
    PRIVATE Threads::Threads
)

# flags
if(NOT MSVC)
    target_compile_options(snake_game PRIVATE
    -Wall 
    -Wextra
    -Wpedantic
     ) 
endif()
