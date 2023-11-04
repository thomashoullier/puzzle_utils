#include "predicates_test.hpp"

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

TEST_CASE("oddeven", "[oddeven]") {
  SECTION("calling") {
    std::views::iota(1,10) | std::views::filter(pzu::is_even);
    std::views::iota(1,10) | std::views::filter(pzu::is_odd);
    SUCCEED("calling");
  }
  SECTION("correctness") {
    auto r = std::views::iota(1,10) | std::views::filter(pzu::is_even);
    auto s = 0;
    for (const auto &el : r) {
      s += el;
    }
    REQUIRE(s == 20);
  }
}
