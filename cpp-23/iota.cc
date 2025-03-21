#include <ranges>
#include <vector>
#include <format>
#include <iostream>

/*
  What Does iota Stand For?

  Now, about std::views::iota: it’s a range factory in the C++20 Ranges library (available under <ranges>), and its name comes from both mathematics and programming tradition.

  Mathematical Origin: In mathematics, "iota" (ι) is the ninth letter of the Greek alphabet, often used as a symbol for an infinitesimally small quantity or as an index in sequences. The APL programming language popularized iota as a function to generate a sequence of integers (e.g., ι5 generates 1 2 3 4 5), and this convention carried over to other languages.

  C++ Meaning: In C++, std::views::iota generates a lazy view of a sequence of numbers (or any incrementable type), starting from a given value and continuing indefinitely (or until a specified bound). It’s similar to Python’s range() or Haskell’s list comprehensions, but as a range view, it computes values on demand rather than creating a container upfront.

  Syntax and Usage

  std::views::iota( first ): Generates an unbounded sequence starting at first, incrementing by 1 each time (e.g., 0, 1, 2, 3, ... for integers).

  std::views::iota( first, last ): Generates a bounded sequence from first up to (but not including) last.
*/
int main() {
    auto v = std::views::iota( 0, 5 );

    for ( int x : v ) {
       std::cout << std::format( "{} ", x );
    }

    std::cout << '\n';
}
