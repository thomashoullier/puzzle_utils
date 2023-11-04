/** @file */
#ifndef FIBONACCI_HPP
#define FIBONACCI_HPP

#include <ranges>
#include <iterator>
#include <utility>

namespace pzu {
  /** @brief Fibonacci range.

      It is an infinite sequence.
      It begins as [0, 1, 1, 2, 3, 5, ...].
      Credit goes to [Brindle2021] and [Quimby2022]. */
  template <std::incrementable T = std::size_t>
  class fibonacci : public std::ranges::view_interface<fibonacci<T>> {
  public:
    struct iterator;

    auto begin() const { return iterator{}; }
    auto end() const { return std::unreachable_sentinel; }
  };

  template <std::incrementable T>
  struct fibonacci<T>::iterator {
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
}

#endif // FIBONACCI_HPP
