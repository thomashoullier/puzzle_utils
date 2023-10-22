#include <RangePrinter.hpp>
#include <ranges>

int main () {
  auto r = std::views::iota(1,6);
  auto rp = RangePrinter(3);
  r | rp;
}
