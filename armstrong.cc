// https://www.geeksforgeeks.org/cpp-coding-interview-questions-and-answers/
// 18. Write a Program to Check Whether a Number is an Armstrong Number or Not
// An Armstrong number of three digits is an integer such that the sum of the cubes of its digits is equal to the number itself.
// For example, 371 is an Armstrong number since 3**3 + 7**3 + 1**3 = 371.
#include <string>
#include <format>
#include <iostream>
#include <bitset>
#include <cmath>
#include <vector>
#include <assert.h>
#include <cstdint>
#include <limits.h>

bool isarmstrong( int n ) {
   int rem = n;
   int arm = 0;

   while ( rem ) {
      int d = rem % 10;
      int dv = d*d*d;
      arm += dv;

      rem /= 10;
   }

   return (arm == n);
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

   bool p = isarmstrong( n );

   std::cout << std::format( "{} -> {}\n", n, p );

   return 0;
}

// vim: et ts=3 sw=3
