#include <iostream>
#include <ranges>
#include <fmt/ranges.h>

template<std::ranges::view V>
void print_range (const V& range) {
  fmt::print("{}\n", range);
}

class RangePrinter {};

template<std::ranges::view V>
void operator| (const V& range, RangePrinter rp) {
  print_range(range);
}

int main () {
  auto range_toprint = std::views::iota(1,6);
  range_toprint | RangePrinter();
}
