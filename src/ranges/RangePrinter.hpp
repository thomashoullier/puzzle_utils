/** @file */
#ifndef RANGEPRINTER_HPP
#define RANGEPRINTER_HPP

#include <iostream>
#include <ranges>
#include <fmt/ranges.h>

namespace pzu {
  template <typename R>
  concept ViewableRange = std::ranges::viewable_range<R>;
  // Views which trivially know their size.
  template <typename R>
  concept SizedView = ViewableRange<R> && std::ranges::sized_range<R>;
  // Views of unknown sizes (finite or infinite).
  template <typename R>
  concept UnsizedView = ViewableRange<R> && (not std::ranges::sized_range<R>);

  /** @brief Class for printing ranges. */
  class RangePrinter {
  public:
    /** @brief Default constructor. */
    RangePrinter ();
    /** @brief Constructor with provided length of printing. */
    RangePrinter (std::size_t _print_length);
    /** @brief Constructor with provided ostream. */
    RangePrinter (std::ostream &_ostream);
    /** @brief Constructor with ostream and length of printing. */
    RangePrinter (std::ostream &_ostream, std::size_t _print_length);

    /** @brief Print a SizedView. */
    void print (SizedView auto range) {
      auto str = (length_set) ?
        fmt::format("{}\n", range | std::views::take(print_length))
        : fmt::format("{}\n", range);
      (*ostream) << str;
    }

    /** @brief Print an UnsizedView, of unknown length. */
    void print (UnsizedView auto range) {
      auto str = fmt::format("{}\n", range | std::views::take(print_length));
      (*ostream) << str;
    }

  private:
    /** @brief Number of items to print from the range. */
    std::size_t print_length;
    /** @brief Was the print length set by the user? */
    bool length_set;
    /** @brief The stream to print to. */
    std::ostream *ostream;
  };

  /** @brief Pipe operator overloading for RangePrinter. */
  auto operator| (const ViewableRange auto &range, RangePrinter rp) -> decltype(range) {
    rp.print(range);
    return range;
  }

  /** @brief Short hand for using a RangePrinter() instance directly. */
  extern RangePrinter rangePrinter;
}

#endif // RANGEPRINTER_HPP
