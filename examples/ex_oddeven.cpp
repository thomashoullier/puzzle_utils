#include <iostream>
#include <pzu.hpp>

const auto is_even = [](const auto x) {
  return x % 2 == 0;
};

const auto is_odd = [](const auto x) {
  return (not is_even(x));
};

int main () {
  std::views::iota(1,10) | std::views::filter(is_even) | pzu::rangePrinter;
  std::views::iota(1,10) | std::views::filter(is_odd) | pzu::rangePrinter;
}
