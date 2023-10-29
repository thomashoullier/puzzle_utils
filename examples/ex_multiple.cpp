#include <iostream>
#include <pzu.hpp>

template <typename Arg>
auto is_multiple_of (Arg arg) {
  return [arg](const auto x) {
    return (x % arg == 0);
  };
}

template <typename... Args>
auto is_multiple_of_any (Args... args) {
  return [args...](const auto x) {
    return (... or (x % args == 0));
  };
}

template <typename... Args>
auto is_multiple_of_all (Args... args) {
  return [args...](const auto x) {
    return (... and (x % args == 0));
  };
}

int main () {
  std::views::iota(1,20)
    | std::views::filter(is_multiple_of(3))
    | pzu::rangePrinter;
  std::views::iota(1,20)
    | std::views::filter(is_multiple_of_any(3,5))
    | pzu::rangePrinter;
  std::views::iota(1,20)
    | std::views::filter(is_multiple_of_all(3,5))
    | pzu::rangePrinter;
}
