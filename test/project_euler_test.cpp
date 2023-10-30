#include "project_euler_test.hpp"

TEST_CASE("Project Euler", "[project_euler]") {
  SECTION("Problem 1") {
    auto sum_mults = std::views::iota(1,1000)
      | std::views::filter(pzu::is_multiple_of_any(3,5))
      | pzu::rangeSum;
    REQUIRE(sum_mults == 233168);
  }
}
