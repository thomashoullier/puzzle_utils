#include <iostream>
#include <ranges>
#include <pzu.hpp>

int main () {
  std::views::iota(1,10) | std::views::filter(pzu::gt(5)) | pzu::rangePrinter;
  std::views::iota(1,10) | std::views::filter(pzu::gte(5)) | pzu::rangePrinter;
  std::views::iota(1,10) | std::views::filter(pzu::lt(5)) | pzu::rangePrinter;
  std::views::iota(1,10) | std::views::filter(pzu::lte(5)) | pzu::rangePrinter;
}
