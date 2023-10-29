#include <iostream>
#include <ranges>
#include <fmt/ranges.h>
#include <pzu.hpp>

int main () {
  auto range_toprint = std::views::iota(1,6);

  // Manual way.
  for (const auto &i : range_toprint) {
    std::cout << i << " ";
  }
  std::cout << std::endl;

  // With the fmt library.
  fmt::print("{}\n", range_toprint);

  // With pzu.
  range_toprint | pzu::rangePrinter;
  range_toprint | pzu::RangePrinter(3);
  range_toprint | pzu::RangePrinter(std::cout);
  range_toprint | pzu::RangePrinter(std::cout, 3);
  std::views::iota(1) | pzu::rangePrinter
                      | std::views::take(2)
                      | pzu::rangePrinter;

  auto even = [](int i) { return 0 == i % 2; };
  std::views::iota(1,20) | std::views::filter(even) | pzu::rangePrinter;
}
