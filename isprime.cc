// https://www.geeksforgeeks.org/cpp-coding-interview-questions-and-answers/
// 16. Write a program to check if a number is a prime number
#include <string>
#include <format>
#include <iostream>
#include <bitset>
#include <cmath>
#include <vector>

bool isprime( int n ) {
#if 0
   // dumbest way possible, one divide for each integer less than the candidate.
   for ( int i = 2 ; i < n ; i++ ) {
      if ( (n % i) == 0 ) {
         return false;
      }
   }

   return true;
#else
   // This assumes that vector<bool> is optimized to use bitsets for bool arrays.
   //
   // Perhaps overkill: Using a prime seive could give us all the primes less than a certain amount (if we didn't get out early).
   std::vector<bool> s; // prime seive
   s.resize( n + 1, true );
   for ( int i = 2 ; i < (std::sqrt(n)+1) ; i++ ) {
      if ( s[i] ) {
         for ( int j = i + i ; j <= n ; j += i ) {
            s[j] = false;
         }
      }
      if ( s[n] == false ) {
         return false;
      }
   }

   return true;
#endif
}

// shell test case: for i in {1..17}; do ./exe/isprime $i ; done
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

   bool prime = isprime( n );

   std::cout << std::format( "{} -> {}\n", n, prime );

   return 0;
}

// vim: et ts=3 sw=3
