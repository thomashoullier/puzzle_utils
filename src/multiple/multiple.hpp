#ifndef MULTIPLE_H
#define MULTIPLE_H

namespace pzu {
  // Lambda of x for a predicate over the args: is x a multiple of all the args
  // simulataneously?
  template <typename... Args>
  auto is_multiple_of (Args... args) {
    return [args...](const auto x) {
      return (... && (x % args == 0));
    };
  }
}

#endif // MULTIPLE_H
