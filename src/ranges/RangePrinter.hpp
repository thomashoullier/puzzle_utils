#ifndef RANGEPRINTER_HPP
#define RANGEPRINTER_HPP

#include <ranges>
#include <fmt/ranges.h>

template <typename R>
concept SizedRange = std::ranges::sized_range<R>;

class RangePrinter {
public:
  RangePrinter ();
  RangePrinter (std::size_t _print_length);

  void print (const SizedRange auto &range) {
    (length_set) ?
      fmt::print("{}\n", range | std::views::take(print_length))
      : fmt::print("{}\n", range);
  }

  void print (const auto &range) {
    fmt::print("{}\n", range | std::views::take(print_length));
  }

private:
  std::size_t print_length;
  bool length_set;
};

auto operator| (const auto &range, RangePrinter rp) -> decltype(range) {
  rp.print(range);
  return range;
}

extern RangePrinter rangePrinter;

#endif // RANGEPRINTER_HPP
