# Build script for the test program
cmake_minimum_required(VERSION 3.0)
project(parse_date)

#{{{Variables: SRCS INCDIRS LINKDIRS LIBS CMAKE_MODULE_PATH

file(GLOB SRCS *.cpp)
set(INCDIRS "${CMAKE_CURRENT_SOURCE_DIR}")
set(INCDIRS_SYS "")
set(LIBS "")
#}}}


add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/.." "${CMAKE_CURRENT_BINARY_DIR}/parse_date")




#{{{CXXFLAGS

# Set build type when generating the Makefile like: cmake -DCMAKE_BUILD_TYPE=Debug ..
set(CMAKE_CXX_FLAGS         "${CMAKE_CXX_FLAGS}         -std=c++11 -Wall -Wextra -Wpedantic -Werror -Wfatal-errors -Os")
set(CMAKE_CXX_FLAGS_DEBUG   "${CMAKE_CXX_FLAGS_DEBUG}   -std=c++11 -Wall -Wextra -Wpedantic -Werror -Wfatal-errors -O0 -ggdb -DDEBUG -save-temps")
#}}}


add_executable(parse_date_test ${SRCS})
target_link_libraries(parse_date_test ${LIBS} )
target_include_directories(parse_date_test PUBLIC ${INCDIRS})
target_include_directories(parse_date_test SYSTEM PUBLIC ${INCDIRS_SYS})
