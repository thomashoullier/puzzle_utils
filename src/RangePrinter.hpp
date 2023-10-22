#ifndef RANGEPRINTER_HPP
#define RANGEPRINTER_HPP

#include <ranges>
#include <fmt/ranges.h>

class RangePrinter {
public:
  RangePrinter(std::size_t _print_length);

  template <std::ranges::view R,
            std::enable_if_t<std::ranges::sized_range<R>, bool> = true>
  void print (const R& range) {
    fmt::print("{}\n", range);
  }

  template <std::ranges::view R,
            std::enable_if_t<!std::ranges::sized_range<R>, bool> = true>
  void print (const R& range) {
    fmt::print("{}\n", range | std::views::take(print_length));
  }

private:
  std::size_t print_length;
};

template <std::ranges::view V>
const V& operator| (const V& range, RangePrinter rp) {
  rp.print(range);
  return range;
}

#endif // RANGEPRINTER_HPP
