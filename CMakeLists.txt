cmake_minimum_required(VERSION 3.27)
project(Voenmeh CXX)

set(CMAKE_C_STANDARD 23)
set(CMAKE_CXX_STANDARD 23)


add_executable(voenmeh main.cpp)

find_package(fmt CONFIG REQUIRED)
target_link_libraries(voenmeh PRIVATE fmt::fmt-header-only)

find_package(glm CONFIG REQUIRED)
target_link_libraries(voenmeh PRIVATE glm::glm)