// https://www.geeksforgeeks.org/cpp-coding-interview-questions-and-answers/
// Write a Program to Remove the Vowels from a String
//#include <assert.h>
//#include <ctype.h>
//#include <locale.h>
#include <stdio.h>
#include <unordered_set>
#include <string>
//#include <iostream>

std::unordered_set<char> latin1vowels {
   'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u',
   '\xC0', '\xC1', '\xC2', '\xC3', '\xC4', '\xC5', // accented A characters
   '\xC8', '\xC9', '\xCA', '\xCB',                 // accented E characters
   '\xCC', '\xCD', '\xCE', '\xCF',                 // accented I characters
   '\xD2', '\xD3', '\xD4', '\xD5', '\xD6',         // accented O characters
   '\xD9', '\xDA', '\xDB', '\xDC',                 // accented U characters
   '\xE0', '\xE1', '\xE2', '\xE3', '\xE4', '\xE5', // accented a characters
   '\xE8', '\xE9', '\xEA', '\xEB',                 // accented e characters
   '\xEC', '\xED', '\xEE', '\xEF',                 // accented i characters
   '\xF2', '\xF3', '\xF4', '\xF5', '\xF6',         // accented o characters
   '\xF9', '\xFA', '\xFB', '\xFC'                  // accented u characters
};

std::string removevowels(const std::string & s) {
   std::string r;
   r.reserve( s.length() );

   for ( char c : s ) {
      if ( latin1vowels.contains( c ) ) {
         continue;
      }

      r.push_back( c );
   }

   return r;
}

int main()
{
#if 0
   // setlocale(LC_ALL, "en_CA.UTF-8");
   char* loc = setlocale( LC_ALL, "en_CA.iso88591" );
   assert( loc );
#endif

   // printf instead of cout to check out the generated assembly without the clutter:
   //
   // objdump -dr --no-show-raw-insn  removevowels 
   printf( "%s\n", removevowels( "Hi there, how are \xFB\xE2you." ).c_str() );
   //std::cout << removevowels( "Hi there, how are \xFB\xE2you." ) << '\n';

   return 0;
}

// vim: et ts=3 sw=3 fileencoding=latin1
