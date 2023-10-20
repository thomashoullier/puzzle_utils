#include <iostream>
#include <ranges>

template<std::ranges::view V>
void print_range (const V& range) {
  for (const auto& item : range) {
    std::cout << item << " ";
  }
  std::cout << std::endl;
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
