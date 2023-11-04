#include <ranges>
#include <iostream>
#include <pzu.hpp>

// Unsupported C++23 feature
// #include <generator>
//
// std::generator <int> fibonacci () {
//   auto f0 = 0;
//   auto f1 = 1;
//   while (true) {
//     auto f2 = f0 + f1;
//     f0 = f1;
//     f1 = f2;
//     co_yield f2;
//   }
// }

int main () {
  std::cout << "# ex_fibonacci #" << std::endl;
  pzu::fibonacci() | std::views::take(10) | pzu::rangePrinter;
  auto first = pzu::fibonacci() | std::views::take(1);
  std::cout << *first.begin() << std::endl;
}
