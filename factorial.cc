// https://www.geeksforgeeks.org/cpp-coding-interview-questions-and-answers/
// 14. Write a Program to Find the Factorial of a Number Using Loops
#include <string>
#include <format>
#include <iostream>

int factorial( int n ) {
   int r = 1;

   for ( int i = 1 ; i <= n ; i++ ) {
      r *= i;
   }

   return r;
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

   int r = factorial( n );

   std::cout << std::format( "{} -> {}\n", n, r );

   return 0;
}
