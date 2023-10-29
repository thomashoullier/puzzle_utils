#include <iostream>
#include <pzu.hpp>

int main () {
  std::views::iota(1,20)
    | std::views::filter(pzu::is_multiple_of(3))
    | pzu::rangePrinter;
  std::views::iota(1,20)
    | std::views::filter(pzu::is_multiple_of_any(3,5))
    | pzu::rangePrinter;
  std::views::iota(1,20)
    | std::views::filter(pzu::is_multiple_of_all(3,5))
    | pzu::rangePrinter;
}
