#ifndef RANGEPRINTER_HPP
#define RANGEPRINTER_HPP

#include <ranges>
#include <fmt/ranges.h>

namespace pzu {
  template <typename R>
  concept ViewableRange = std::ranges::viewable_range<R>;
  // Views which trivially know their size.
  template <typename R>
  concept SizedView = ViewableRange<R> && std::ranges::sized_range<R>;
  // Other views of unknown sizes.
  template <typename R>
  concept OtherView = ViewableRange<R> && (not std::ranges::sized_range<R>);

  class RangePrinter {
  public:
    RangePrinter ();
    RangePrinter (std::size_t _print_length);

    void print (SizedView auto range) {
      (length_set) ?
        fmt::print("{}\n", range | std::views::take(print_length))
        : fmt::print("{}\n", range);
    }

    void print (OtherView auto range) {
      fmt::print("{}\n", range | std::views::take(print_length));
    }

  private:
    std::size_t print_length;
    bool length_set;
  };

  auto operator| (const ViewableRange auto &range, RangePrinter rp) -> decltype(range) {
    rp.print(range);
    return range;
  }

  extern RangePrinter rangePrinter;
}

#endif // RANGEPRINTER_HPP
