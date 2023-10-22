#include "RangePrinter.hpp"

RangePrinter::RangePrinter(std::size_t _print_length = 10) :
  print_length(_print_length) {}

void RangePrinter::print (const SizedRange auto &range) {
  fmt::print("{}\n", range);
}

void RangePrinter::print (const auto &range) {
  fmt::print("{}\n", range | std::views::take(print_length));
}

auto operator| (const auto &range, RangePrinter rp) -> decltype(range) {
  rp.print(range);
  return range;
}
