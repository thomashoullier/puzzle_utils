/** @file */
#ifndef RANGESUM_HPP
#define RANGESUM_HPP

#include <numeric>

namespace pzu {
  /** @brief Class for summing range items. */
  class RangeSum {
  public:
    /** @brief Default constructor. */
    RangeSum () {};

    /** @brief Sum method over a range. */
    auto sum (const auto &range) const {
      return std::reduce(range.begin(), range.end());
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
