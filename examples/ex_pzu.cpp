#include <pzu.hpp>
#include <ranges>

int main () {
  auto r = std::views::iota(1,6);
  r | pzu::rangePrinter;
  r | pzu::RangePrinter(3);
  r | pzu::RangePrinter(15);
  r | pzu::rangePrinter | pzu::RangePrinter(3);
  std::views::iota(1) | pzu::rangePrinter;
  std::views::iota(1) | pzu::RangePrinter(3);
}
