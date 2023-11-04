#include <iostream>
#include <ranges>
#include <pzu.hpp>

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

int main () {
  std::views::iota(1,10) | std::views::filter(gt(5)) | pzu::rangePrinter;
  std::views::iota(1,10) | std::views::filter(gte(5)) | pzu::rangePrinter;
  std::views::iota(1,10) | std::views::filter(lt(5)) | pzu::rangePrinter;
  std::views::iota(1,10) | std::views::filter(lte(5)) | pzu::rangePrinter;
}
