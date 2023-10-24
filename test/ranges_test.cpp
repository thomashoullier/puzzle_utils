#include "ranges_test.hpp"

TEST_CASE("ranges", "[ranges]") {
  SECTION("calling") {
    auto range_toprint = std::views::iota(1,6);
    range_toprint | pzu::rangePrinter;
    SUCCEED("pzu::rangePrinter");
    range_toprint | pzu::RangePrinter(3);
    SUCCEED("pzu::RangePrinter()");
    std::views::iota(1) | pzu::rangePrinter;
    SUCCEED("Default with infinite sequence.");
    std::views::iota(1) | pzu::rangePrinter
                        | std::views::take(2)
                        | pzu::rangePrinter;
    SUCCEED("Sequence with passing range.");
  }

  SECTION("non-regression") {
    auto even = [](int i) { return 0 == i % 2; };
    std::views::iota(1,20) | std::views::filter(even) | pzu::rangePrinter;
    SUCCEED("Bug #1");
  }
}
