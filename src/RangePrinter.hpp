#ifndef RANGEPRINTER_HPP
#define RANGEPRINTER_HPP

#include <ranges>
#include <fmt/ranges.h>

template <typename R>
concept SizedRange = std::ranges::sized_range<R>;

class RangePrinter {
public:
  RangePrinter(std::size_t _print_length);

  void print (const SizedRange auto &range);
  void print (const auto &range);

private:
  std::size_t print_length;
};

auto operator| (const auto &range, RangePrinter rp) -> decltype(range);

#endif // RANGEPRINTER_HPP
