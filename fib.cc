// https://www.geeksforgeeks.org/cpp-coding-interview-questions-and-answers/
// 19. Write a Program to find the nth fibonacci number.
#include <string>
#include <format>
#include <iostream>
#include <cmath>

// Is it cheating to look at my own Fibonacci series notes?
//
// https://peeterjoot.com/2020/11/20/deriving-the-nth-fibonacci-number-formula/ 
// F_n = (\phi^n - \bar{\phi}^{n})/\sqrt{5}
// where:
//   \phi       = (1 + \sqrt{5})/2;
//   \bar{\phi} = (1 - \sqrt{5})/2;
int fib( int n ) {
    double rootfive = std::sqrt( 5 );
    double phi = (1.0 + rootfive)/2.0;
    double phibar = (1.0 - rootfive)/2.0;
    double nphi = std::pow( phi, n );
    double nphibar = std::pow( phibar, n );

    double fib = (nphi - nphibar)/rootfive;

    return fib;
}

int main( int argc, char ** argv ) {
   if ( argc != 2 ) {
      std::cerr << "expected a single non-negative integer parameter\n";
      return 1;
   }

   int n;
   try {
      n = std::stoi( argv[1] );
   } catch ( std::exception & e ) {
      std::cerr << std::format( "Failed to convert '{}' to an integer\n", argv[1] );
      return 2;
   }

   if ( n < 0 ) {
      std::cerr << std::format( "Supplied value {} is not a positive integer\n", n );
      return 2;
   }

   int f = fib( n );

   std::cout << std::format( "{} -> {}\n", n, f );

   return 0;
}

// vim: et ts=3 sw=3
