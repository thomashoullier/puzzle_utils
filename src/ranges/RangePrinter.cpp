#include "RangePrinter.hpp"

RangePrinter::RangePrinter () {
  print_length = 10;
  length_set = false;
}

RangePrinter::RangePrinter (std::size_t _print_length) {
  print_length = _print_length;
  length_set = true;
}

RangePrinter rangePrinter;
