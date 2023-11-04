#include "ranges_test.hpp"

TEST_CASE("RangePrinter", "[RangePrinter]") {
  boost::iostreams::stream<boost::iostreams::null_sink>
    nullOstream((boost::iostreams::null_sink()));
  SECTION("calling") {
    auto rp = pzu::RangePrinter(0);
    (void)rp; // Silence unused warning
    SUCCEED("Instantiating a RangePrinter(print_length)");
    auto range_toprint = std::views::iota(1,6);
    range_toprint | pzu::RangePrinter(nullOstream);
    SUCCEED("RangePrinter(ostream)");
    range_toprint | pzu::RangePrinter(nullOstream, 3);
    SUCCEED("RangePrinter(ostream, print_length)");
    std::views::iota(1) | pzu::RangePrinter(nullOstream);
    SUCCEED("Default with infinite sequence.");
    std::views::iota(1) | pzu::RangePrinter(nullOstream)
                        | std::views::take(2)
                        | pzu::RangePrinter(nullOstream);
    SUCCEED("Sequence with passing range.");
  }

  SECTION("non-regression") {
    auto even = [](int i) { return 0 == i % 2; };
    std::views::iota(1,20) | std::views::filter(even)
                           | pzu::RangePrinter(nullOstream);
    SUCCEED("Bug #1");
  }
}

TEST_CASE("RangeSum", "[RangeSum]") {
  SECTION("calling") {
    auto s = std::views::iota(1,20) | pzu::rangeSum;
    (void)s;
    SUCCEED("rangeSum");
  }
  SECTION("correctness") {
    auto s = std::views::iota(1,20) | pzu::rangeSum;
    REQUIRE(s == 190);
  }
  SECTION("Non-regression") {
    auto s = pzu::fibonacci() | std::views::take(10) | pzu::rangeSum;
    REQUIRE(s == 88);
  }
}

TEST_CASE("fibonacci", "[fibonacci]") {
  SECTION("calling") {
    auto f = pzu::fibonacci();
    (void)f;
    SUCCEED("fibonacci()");
  }
  SECTION("correctness") {
    auto first = pzu::fibonacci();
    REQUIRE(*first.begin() == 0);
  }
}
