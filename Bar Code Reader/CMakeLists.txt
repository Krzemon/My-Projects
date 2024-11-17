cmake_minimum_required(VERSION 3.14)

project(BarCodeReader VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON) # Requirement of this standard
set(CMAKE_CXX_EXTENSIONS OFF)

# Build type - Debug by default, but can be changed to: Release
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

set(CMAKE_CXX_FLAGS_DEBUG "-g -Wall -Wextra")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -Wall")

set(INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)

include_directories(${INCLUDE_DIR})

file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp")

# Znalezienie OpenCV
find_package(OpenCV REQUIRED)

add_executable(${PROJECT_NAME} main.cpp ${SOURCES})

# Dodanie katalogów z nagłówkami
target_include_directories(${PROJECT_NAME} PRIVATE include)

# Podlinkowanie bibliotek OpenCV
target_link_libraries(${PROJECT_NAME} PRIVATE ${OpenCV_LIBS})

# Ustawienia katalogu wyjściowego
set_target_properties(${PROJECT_NAME} PROPERTIES 
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)