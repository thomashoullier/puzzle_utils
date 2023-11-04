/** @file */
#ifndef COMPARISONS_HPP
#define COMPARISONS_HPP

#include <functional>

namespace pzu {
  template <typename Comparison>
  constexpr auto lambda_predicate_compare (const Comparison comp) {
    return [comp](const auto y) {
      return [y, comp](const auto x) {
        return comp(x, y);
      };
    };
  }

  constexpr auto gt = lambda_predicate_compare(std::greater<>());
  constexpr auto gte = lambda_predicate_compare(std::greater_equal<>());
  constexpr auto lt = lambda_predicate_compare(std::less<>());
  constexpr auto lte = lambda_predicate_compare(std::less_equal<>());
}

#endif // COMPARISONS_HPP
