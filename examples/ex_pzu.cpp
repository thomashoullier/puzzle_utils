#include <pzu.hpp>
#include <ranges>

int main () {
  auto r = std::views::iota(1,6);
  r | rangePrinter;
  r | RangePrinter(3);
  r | RangePrinter(15);
  r | rangePrinter | RangePrinter(3);
  std::views::iota(1) | rangePrinter;
  std::views::iota(1) | RangePrinter(3);
}
