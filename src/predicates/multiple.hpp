/** @file */
#ifndef MULTIPLE_H
#define MULTIPLE_H

namespace pzu {
  /** @brief Defines what a multiple of two items is.

   x is a multiple of y if (x % y == 0) */
  const auto is_multiple (const auto x, const auto y) {
    return (x % y == 0);
  }

  /** @brief Return a lambda function for testing whether a given
   number is a multiple of the provided argument. */
  template <typename Arg>
  auto is_multiple_of (Arg arg) {
    return [arg](const auto x) {
      return is_multiple(x, arg);
    };
  }

  /** @brief Return a lambda function for testing whether a number is
  a multiple of any of the provided arguments. */
  template <typename... Args>
  auto is_multiple_of_any (Args... args) {
    return [args...](const auto x) {
      return (... or is_multiple(x, args));
    };
  }

  /** @brief Return a lambda function for testing whether a number is
   a multiple of all of the provided arguments. */
  template <typename... Args>
  auto is_multiple_of_all (Args... args) {
    return [args...](const auto x) {
      return (... and is_multiple(x, args));
    };
  }
}

#endif // MULTIPLE_H
