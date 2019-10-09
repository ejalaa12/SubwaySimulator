cmake_minimum_required(VERSION 3.6)
project(SubwaySimulator)

set(CMAKE_CXX_STANDARD 14)

find_package(Boost REQUIRED COMPONENTS
    date_time)

include_directories(
    include
    Boost_INCLUDE_DIRS
)

# Manually add files
set(src_files
    src/simulation/Entity.cpp
    src/simulation/SimEngine.cpp
    src/simulation/Event.cpp
    src/utilities/LocalDateTime.cpp
    src/utilities/Random.cpp)

# Automatically add files
#file(GLOB src_files "src/*.cpp")

add_executable(SubwaySimulator main.cpp ${src_files})
target_link_libraries(SubwaySimulator Boost::date_time)

# FOR TESTING ONLY
add_executable(test test.cpp)
