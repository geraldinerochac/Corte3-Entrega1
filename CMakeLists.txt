cmake_minimum_required(VERSION 3.10)
project(TercerCorte_Entrega1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Boost REQUIRED COMPONENTS system date_time)

include_directories(exercism)

# LeetCode
add_executable(underground_system leetcode/underground_system.cpp)
add_executable(atm leetcode/atm.cpp)
add_executable(auction_system leetcode/auction_system.cpp)

# Exercism
add_executable(meetup_exec exercism/meetup.cpp)
target_link_libraries(meetup_exec Boost::date_time)

add_executable(clock_exec exercism/clock.cpp)