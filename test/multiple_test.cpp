#include "multiple_test.hpp"

TEST_CASE("multiple", "[multiple]") {
  SECTION("calling") {
    std::views::iota(1,20) | std::views::filter(pzu::is_multiple_of(2,3));
    SUCCEED("multiple(2,3)");
  }
}
