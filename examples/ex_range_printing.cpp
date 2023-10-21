#include <iostream>
#include <ranges>
#include <fmt/ranges.h>

class RangePrinter {
public:
  RangePrinter () {
    print_length = 10;
  };

  RangePrinter (std::size_t _print_length) {
    print_length = _print_length;
  };

  template <typename R,
            std::enable_if_t<std::ranges::sized_range<R>, bool> = true>
  void print (const R& range) {
    fmt::print("{}\n", range);
  }

  template <typename R,
            std::enable_if_t<!std::ranges::sized_range<R>, bool> = true>
  void print (const R& range) {
    fmt::print("{}\n", range | std::views::take(print_length));
  }

private:
  std::size_t print_length;
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
  range_toprint | rangePrinter;
  //range_toprint | RangePrinter(3) | rangePrinter;
  std::views::iota(1) | RangePrinter(3);
  std::views::iota(1) | rangePrinter;
}
