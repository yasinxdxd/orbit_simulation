cmake_minimum_required(VERSION 3.0)
project(Challenge VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)


include_directories("./include")
file(GLOB SOURCES
"./src/Main.cpp"
"./src/App.cpp"
"./src/Entities.cpp")

set(PROJECT_LINK_LIBS engine.lib)

link_directories("./lib")

add_executable(Challenge ${SOURCES})
target_link_libraries(Challenge ${PROJECT_LINK_LIBS})