#include <iostream>
#include <ranges>

template <typename... Args>
auto is_multiple_of (Args... args) {
  return [args...](const auto x) {
    return (... && (x % args == 0));
  };
}

int main () {
  auto r = std::views::iota(1, 20) | std::views::filter(is_multiple_of(2, 3));

  for (int i : r) {
    std::cout << i << " ";
  } std::cout << std::endl;
}
