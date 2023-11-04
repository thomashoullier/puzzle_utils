/** @file */
#ifndef RANGESUM_HPP
#define RANGESUM_HPP

#include <functional>
#include <algorithm>

namespace pzu {
  /** @brief Class for summing range items. */
  class RangeSum {
  public:
    /** @brief Default constructor. */
    RangeSum () {};

    /** @brief Sum method over a range. */
    auto sum (auto range) const {
      return std::ranges::fold_left(range, 0, std::plus<>());
    }
  };

  /** @brief Sum method through pipe operator. */
  auto operator| (const auto &range, const RangeSum &rs) {
    return rs.sum(range);
  }

  /** @brief Shorthand for using a RangeSum() instance directly. */
  extern RangeSum rangeSum;
}

#endif // RANGESUM_HPP
