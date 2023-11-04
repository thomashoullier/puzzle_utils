/** @file */
#ifndef ODDEVEN_HPP
#define ODDEVEN_HPP

namespace pzu {
  /** @brief Lambda predicate for checking even parity. */
  const auto is_even = [](const auto x) {
    return x % 2 == 0;
  };

  /** @brief Lambda predicate for checking odd parity. */
  const auto is_odd = [](const auto x) {
    return (not is_even(x));
  };
}

#endif // ODDEVEN_HPP
