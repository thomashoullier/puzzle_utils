#include <iostream>
#include <ranges>
#include <fmt/ranges.h>

class RangePrinter {
public:
  template<std::ranges::view V>
  void print (const V& range) {
    static_assert(std::ranges::sized_range<V>,
                  "Range must be a sized_range for printing!");
    fmt::print("{}\n", range);
  }
};

template<std::ranges::view V>
const V& operator| (const V& range, RangePrinter rp) {
  rp.print(range);
  return range;
}

RangePrinter rangePrinter;

int main () {
  auto range_toprint = std::views::iota(1,6);
  range_toprint | rangePrinter | std::views::take(3) | rangePrinter;
}
