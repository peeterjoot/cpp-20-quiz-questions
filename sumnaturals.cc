// https://www.geeksforgeeks.org/cpp-coding-interview-questions-and-answers/
// 13. Write a Program to Find the Sum of the First N Natural Numbers
#include <string>
#include <format>
#include <iostream>

int sumnaturals( int n ) {
#if 0
   // logical way to do this:
   return n*(1 + n)/2;
#else
   // This is probably the way that was expected.  Looks like the compiler (g++-13) is not smart enough to optimize away this loop:
   int r = 0;
   for ( int i = 1 ; i <= n ; i++ ) {
      r += i;
   }

   return r;
#endif
}

int main( int argc, char ** argv ) {
   if ( argc != 2 ) {
      std::cerr << "expected a single positive integer parameter\n";
      return 1;
   }

   int n;
   try {
      n = std::stoi( argv[1] );
   } catch ( std::exception & e ) {
      std::cerr << std::format( "Failed to convert '{}' to an integer\n", argv[1] );
      return 2;
   }

   if ( n < 1 ) {
      std::cerr << std::format( "Supplied value {} is not a positive integer\n", n );
      return 2;
   }

   int r = sumnaturals( n );

   std::cout << std::format( "{} -> {}\n", n, r );

   return 0;
}
