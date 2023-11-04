#include <ranges>
#include <iterator>
#include <utility>
#include <iostream>
#include <pzu.hpp>

// Unsupported C++23 feature
// #include <generator>
//
// std::generator <int> fibonacci () {
//   auto f0 = 0;
//   auto f1 = 1;
//   while (true) {
//     auto f2 = f0 + f1;
//     f0 = f1;
//     f1 = f2;
//     co_yield f2;
//   }
// }

// view_interface around an iterator.
// Credit goes to [Brindle2021] and [Quimby2022].
template <std::incrementable T>
class fib : public std::ranges::view_interface<fib<T>> {
public:
  struct iterator;

  auto begin() const { return iterator{}; }
  auto end() const { return std::unreachable_sentinel; }
};

template <std::incrementable T>
struct fib<T>::iterator {
  using iterator_category = std::input_iterator_tag;
  using value_type = T;
  using difference_type = std::ptrdiff_t;
  using pointer = T*;
  using reference = T;

  constexpr iterator () noexcept = default;

  iterator& operator++() {
    current = std::exchange(next, current + next);
    return *this;
  }

  iterator operator++(int) {
    iterator current{*this};
    ++(*this);
    return current;
  }

  value_type operator*() const {
    return current;
  }

  bool operator== (const iterator& other) const {
    return current == other.current && next == other.next;
  }

private:
  T current = {};
  T next = T{} + 1;
};

int main () {
  std::cout << "# ex_fibonacci #" << std::endl;
  fib<std::size_t>() | std::views::take(10) | pzu::rangePrinter;
}
