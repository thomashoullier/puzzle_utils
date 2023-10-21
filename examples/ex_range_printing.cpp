#include <iostream>
#include <ranges>
#include <fmt/ranges.h>

template <typename R>
concept SizedRange = std::ranges::sized_range<R>;

class RangePrinter {
public:
  RangePrinter(std::size_t _print_length = 10) : print_length(_print_length) {}

  void print (const SizedRange auto &range) {
    fmt::print("{}\n", range);
  }

  void print (const auto &range) {
    fmt::print("{}\n", range | std::views::take(print_length));
  }

private:
  std::size_t print_length;
};

auto operator| (const auto &range, RangePrinter rp) -> decltype(range) {
  rp.print(range);
  return range;
}

RangePrinter rangePrinter;

int main () {
  auto range_toprint = std::views::iota(1,6);
  range_toprint | rangePrinter | std::views::take(3) | rangePrinter;
  range_toprint | rangePrinter;
  range_toprint | RangePrinter(3) | rangePrinter;
  std::views::iota(1) | RangePrinter(3);
  std::views::iota(1) | rangePrinter;
}
