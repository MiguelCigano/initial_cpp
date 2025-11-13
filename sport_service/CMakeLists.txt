cmake_minimum_required(VERSION 3.10)
project(sports_service LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(USE_SSL "Enable OpenSSL support for httplib (for https)" ON)

# Ajusta estas rutas si tienes tus headers en otro lugar:
set(HTTPLIB_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/external/httplib")
set(NLOHMANN_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/external/")

add_executable(sports_service src/main.cpp)

# Preferible: scoping por target
target_include_directories(sports_service PRIVATE
    ${HTTPLIB_INCLUDE_DIR}
    ${NLOHMANN_INCLUDE_DIR}
)

if(USE_SSL)
    find_package(OpenSSL REQUIRED)
    if(NOT OpenSSL_FOUND)
        message(FATAL_ERROR "OpenSSL not found but USE_SSL=ON")
    endif()
    target_compile_definitions(sports_service PRIVATE CPPHTTPLIB_OPENSSL_SUPPORT)
    target_link_libraries(sports_service PRIVATE OpenSSL::SSL OpenSSL::Crypto)
endif()

# Mensaje útil
message(STATUS "HTTPLIB include: ${HTTPLIB_INCLUDE_DIR}")
message(STATUS "NLOHMANN include: ${NLOHMANN_INCLUDE_DIR}")
message(STATUS "USE_SSL = ${USE_SSL}")
