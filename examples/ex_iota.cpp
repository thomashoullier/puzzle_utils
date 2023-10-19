#include <iostream>
#include <ranges>

int main () {
  // Usage as an unbounded sequence
  for (auto i : std::views::iota(1) | std::views::take (5)) {
    std::cout << i << " ";
  }
  std::cout << std::endl;

  // Usage as a bounded sequence
  for (auto i : std::views::iota(1, 6)) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
}
