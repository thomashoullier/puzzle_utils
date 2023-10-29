#include "multiple_test.hpp"

TEST_CASE("multiple", "[multiple]") {
  SECTION("calling") {
    std::views::iota(1,20) | std::views::filter(pzu::is_multiple_of(3));
    SUCCEED("is_multiple_of");
    std::views::iota(1,20) | std::views::filter(pzu::is_multiple_of_any(3,5));
    SUCCEED("is_multiple_of_any");
    std::views::iota(1,20) | std::views::filter(pzu::is_multiple_of_all(3,5));
    SUCCEED("is_multiple_of_all");
  }
}
