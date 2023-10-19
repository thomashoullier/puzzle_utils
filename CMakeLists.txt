project(puzzle_utils)

set(CMAKE_CXX_STANDARD 20)

# Examples
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -O2 -Wextra")
set(EXAMPLES_DIR "${CMAKE_CURRENT_LIST_DIR}/examples")

add_executable(ex_iota "${EXAMPLES_DIR}/ex_iota.cpp")
