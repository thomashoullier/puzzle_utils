/** @file */
#ifndef MULTIPLE_H
#define MULTIPLE_H

namespace pzu {
  /** @brief Return a lambda function for testing whether a number is
  simultaneously a multiple to the provided arguments.

  The number x being a multiple of arg means: x % arg == 0
  */
  template <typename... Args>
  auto is_multiple_of (Args... args) {
    return [args...](const auto x) {
      return (... && (x % args == 0));
    };
  }
}

#endif // MULTIPLE_H
