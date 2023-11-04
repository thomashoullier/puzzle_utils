#include <iostream>
#include <ranges>
#include <algorithm>
#include <numeric>
#include <pzu.hpp>

int main () {
  auto r = std::views::iota(1,20);
  r | pzu::rangePrinter;

  // Sum using fold_left
  auto fold_sum = std::ranges::fold_left(r, 0, std::plus<int>());
  std::cout << "fold_left: " << fold_sum << std::endl;

  // Sum using accumulate
  auto acc_sum = std::accumulate(r.begin(), r.end(), 0);
  std::cout << "accumulate: " << acc_sum << std::endl;

  // reduce
  auto red_sum = std::reduce(r.begin(), r.end());
  std::cout << "reduce: " << red_sum << std::endl;

  // pzu
  auto pzu_sum = r | pzu::rangeSum;
  std::cout << "pzu_sum: " << pzu_sum << std::endl;

  // Other pzu example
  auto s = pzu::fibonacci() | std::views::take(10) | pzu::rangeSum;
  std::cout << s << std::endl;
}
