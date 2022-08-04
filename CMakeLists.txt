cmake_minimum_required(VERSION 3.10)
project(plugintest)

enable_language(CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-Wno-return-type-c-linkage")

add_executable(plugintest main.cpp)
target_link_libraries(plugintest ${CMAKE_DL_LIBS})

add_library(plugin_a SHARED plugin_a.cpp)
add_library(plugin_b SHARED plugin_b.cpp)
