// https://www.geeksforgeeks.org/cpp-coding-interview-questions-and-answers/
// 17. Write a Program to Check if a number is a Palindrome
#include <string>
#include <format>
#include <iostream>
#include <bitset>
#include <cmath>
#include <vector>
#include <assert.h>
#include <cstdint>
#include <limits.h>

bool ispalendrome( int n ) {
#if 0

   std::string s = std::to_string( n );
   size_t len = s.length();

   int j = len-1;
   for ( size_t i = 0 ; i < len ; i++ ) {
      if ( s[i] != s[j] ) {
         return false;
      }
      j--;
   }

   return true;
#elif 0
   // The method above seems like a cheat, as it lets std::to_string do all the work.
   // Here's a slightly more manual way, but there's probably still a smarter way to do it.

   static_assert(INT_MAX == 2147483647, "Expect only this INT_MAX value (used below).");
   const size_t int_max_digits = sizeof("2147483647")-1;
   std::vector<uint8_t> digits{};
   digits.reserve(int_max_digits);
   int rem = n;

   size_t len = 0;
   if ( n == 0 ) {
      digits.push_back(0);
      len++;
   } else {
      while ( rem ) {
         int d = rem % 10;
         rem = rem / 10;

         digits.push_back( d );
         len++;
      }
   }
   assert( digits.size() <= int_max_digits);

   size_t j = len-1;
   for ( size_t i = 0 ; i < len ; i++ ) {
      if ( digits[i] != digits[j] ) {
         return false;
      }
      j--;
   }

   return true;
#else
   // Use of std::vector when our digit array is fixed size is also overkill, and probably hurts.  Ideally
   // std::array shouldn't have any additional cost relative to a C array.
   // In fact: the optimized assembly for these is identical looking, so it doesn't look like std::array costs anything.

   static_assert(INT_MAX == 2147483647, "Expect only this INT_MAX value (used below).");
   constexpr size_t int_max_digits = sizeof("2147483647")-1;
#ifdef USE_PLAIN_C
   uint8_t digits[int_max_digits]{};
#else
   std::array<uint8_t, int_max_digits> digits{};
#endif
   int rem = n;

   size_t len = 0;
   size_t pos = 0;
   if ( n == 0 ) {
      digits[pos] = 0;
      pos++;
      len++;
   } else {
      while ( rem ) {
         int d = rem % 10;
         rem = rem / 10;

         digits[pos] = d;
         pos++;
         len++;
      }
   }
   assert( pos <= int_max_digits);

   size_t j = len-1;
   for ( size_t i = 0 ; i < len ; i++ ) {
      if ( digits[i] != digits[j] ) {
         return false;
      }
      j--;
   }

   return true;
#endif
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

   bool p = ispalendrome( n );

   std::cout << std::format( "{} -> {}\n", n, p );

   return 0;
}

// vim: et ts=3 sw=3
