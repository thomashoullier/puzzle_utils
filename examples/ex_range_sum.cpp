#include <iostream>
#include <ranges>
#include <algorithm>
#include <numeric>
#include <pzu.hpp>

class RangeSum {
public:
  RangeSum () {};

  auto sum (const auto &range) const {
    return std::reduce(range.begin(), range.end());
  }
};

auto operator| (const auto &range, const RangeSum &rs) {
  return rs.sum(range);
}

RangeSum rangeSum;

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

  // pzu draft
  auto pzu_sum = r | rangeSum;
  std::cout << "pzu_sum: " << pzu_sum << std::endl;
}
