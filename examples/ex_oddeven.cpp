#include <iostream>
#include <pzu.hpp>

int main () {
  std::views::iota(1,10) | std::views::filter(pzu::is_even) | pzu::rangePrinter;
  std::views::iota(1,10) | std::views::filter(pzu::is_odd) | pzu::rangePrinter;
}
