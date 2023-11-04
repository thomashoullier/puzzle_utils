cmake_minimum_required(VERSION 3.26)
project(puzzle_utils)

set(CMAKE_BUILD_TYPE "Release")
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/Modules")

# External libraries
include(FetchContent)

FetchContent_Declare(
  fmt
  GIT_REPOSITORY https://github.com/fmtlib/fmt.git
  GIT_TAG 10.1.1
  GIT_SHALLOW TRUE
  GIT_PROGRESS TRUE)
FetchContent_MakeAvailable(fmt)

# pzu library
set(PZU_DIR "${CMAKE_CURRENT_LIST_DIR}")
file(GLOB_RECURSE PZU_SRC "${PZU_DIR}/src/*.cpp")

add_library(pzu STATIC "${PZU_SRC}")
target_include_directories(pzu PUBLIC
  "$<BUILD_INTERFACE:${PZU_DIR}/src>")
target_link_libraries(pzu PUBLIC fmt::fmt-header-only)

option(pzu_build_tests "Build pzu test suite" OFF)
option(pzu_build_coverage "Build pzu test suite code coverage report" OFF)
option(pzu_build_examples "Build pzu examples" OFF)

# pzu test suite
if(pzu_build_tests OR pzu_build_coverage)
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.4.0
  GIT_SHALLOW TRUE
  GIT_PROGRESS TRUE)
FetchContent_MakeAvailable(Catch2)

file(GLOB_RECURSE PZU_TEST_SRC "${PZU_DIR}/test/*.cpp")
add_executable(pzu_test "${PZU_DIR}/test/test_main.cpp" "${PZU_TEST_SRC}")
target_link_libraries(pzu_test PRIVATE pzu Catch2::Catch2WithMain)
endif()

# pzu test code coverage
if(pzu_build_coverage)
include(CodeCoverage)
add_executable(pzu_coverage "${PZU_SRC}" "${PZU_TEST_SRC}")
target_link_libraries(pzu_coverage PRIVATE pzu Catch2::Catch2WithMain)
set_target_properties(pzu_coverage PROPERTIES COMPILE_FLAGS
  "${CMAKE_CXX_FLAGS} -O0 -Wall -fprofile-arcs -ftest-coverage")
setup_target_for_coverage_lcov(
  NAME pzu_coverage_report
  EXECUTABLE pzu_coverage
  BASE_DIRECTORY "${PZU_DIR}"
  EXCLUDE "${PZU_DIR}/test/*" "build/_deps/*" "/usr/*"
)
endif()

# Examples
if (pzu_build_examples)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -O2 -Wextra")
set(EXAMPLES_DIR "${CMAKE_CURRENT_LIST_DIR}/examples")

add_executable(ex_iota "${EXAMPLES_DIR}/ex_iota.cpp")

add_executable(ex_range_printing "${EXAMPLES_DIR}/ex_range_printing.cpp")
target_link_libraries(ex_range_printing PRIVATE
                        fmt::fmt-header-only pzu)

add_executable(ex_multiple "${EXAMPLES_DIR}/ex_multiple.cpp")
target_link_libraries(ex_multiple PRIVATE pzu)

add_executable(ex_range_sum "${EXAMPLES_DIR}/ex_range_sum.cpp")
target_link_libraries(ex_range_sum PRIVATE pzu)

add_executable(ex_fibonacci "${EXAMPLES_DIR}/ex_fibonacci.cpp")
target_link_libraries(ex_fibonacci PRIVATE pzu)

add_executable(ex_oddeven "${EXAMPLES_DIR}/ex_oddeven.cpp")
target_link_libraries(ex_oddeven PRIVATE pzu)

add_executable(ex_comparisons "${EXAMPLES_DIR}/ex_comparisons.cpp")
target_link_libraries(ex_comparisons PRIVATE pzu)

endif()
