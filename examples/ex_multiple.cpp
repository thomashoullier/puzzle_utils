#include <iostream>
#include <pzu.hpp>

int main () {
  auto r = std::views::iota(1, 20)
    | std::views::filter(pzu::is_multiple_of(2, 3));

  for (int i : r) {
    std::cout << i << " ";
  } std::cout << std::endl;
}
