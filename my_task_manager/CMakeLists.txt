cmake_minimum_required(VERSION 3.10)
project(my_task_manager)

# Establecer estandar de C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Incluye carpeta "include" para headers
include_directories(include)

# Encuentra todos los archivos  .cpp en src/
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Crea el ejecutable
add_executable(task_server ${SOURCES})
