#include "RangePrinter.hpp"

namespace pzu {
  RangePrinter::RangePrinter () {
    print_length = 10;
    length_set = false;
    ostream = &std::cout;
  }

  RangePrinter::RangePrinter (std::size_t _print_length) {
    print_length = _print_length;
    length_set = true;
    ostream = &std::cout;
  }

  RangePrinter::RangePrinter (std::ostream &_ostream) {
    print_length = 10;
    length_set = false;
    ostream = &_ostream;
  }

  RangePrinter::RangePrinter (std::ostream &_ostream,
                              std::size_t _print_length) {
    print_length = _print_length;
    length_set = true;
    ostream = &_ostream;
  }

  RangePrinter rangePrinter;
}
