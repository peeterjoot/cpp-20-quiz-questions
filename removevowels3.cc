// https://www.geeksforgeeks.org/cpp-coding-interview-questions-and-answers/
// Write a Program to Remove the Vowels from a String
#include <assert.h>
#include <stdio.h>
#include <string>

// /^}/-1 s/.*/case &: { v = true ; break ; }/
static inline bool isvowel( char c )
{
   bool v = false;
   switch ( c )
   {
      case 'A':
      {
         v = true;
         break;
      }
      case 'E':
      {
         v = true;
         break;
      }
      case 'I':
      {
         v = true;
         break;
      }
      case 'O':
      {
         v = true;
         break;
      }
      case 'U':
      {
         v = true;
         break;
      }
      case 'a':
      {
         v = true;
         break;
      }
      case 'e':
      {
         v = true;
         break;
      }
      case 'i':
      {
         v = true;
         break;
      }
      case 'o':
      {
         v = true;
         break;
      }
      case 'u':
      {
         v = true;
         break;
      }
      case '\xC0':
      {
         v = true;
         break;
      }
      case '\xC1':
      {
         v = true;
         break;
      }
      case '\xC2':
      {
         v = true;
         break;
      }
      case '\xC3':
      {
         v = true;
         break;
      }
      case '\xC4':
      {
         v = true;
         break;
      }
      case '\xC5':
      {
         v = true;
         break;
      }
      case '\xC8':
      {
         v = true;
         break;
      }
      case '\xC9':
      {
         v = true;
         break;
      }
      case '\xCA':
      {
         v = true;
         break;
      }
      case '\xCB':
      {
         v = true;
         break;
      }
      case '\xCC':
      {
         v = true;
         break;
      }
      case '\xCD':
      {
         v = true;
         break;
      }
      case '\xCE':
      {
         v = true;
         break;
      }
      case '\xCF':
      {
         v = true;
         break;
      }
      case '\xD2':
      {
         v = true;
         break;
      }
      case '\xD3':
      {
         v = true;
         break;
      }
      case '\xD4':
      {
         v = true;
         break;
      }
      case '\xD5':
      {
         v = true;
         break;
      }
      case '\xD6':
      {
         v = true;
         break;
      }
      case '\xD9':
      {
         v = true;
         break;
      }
      case '\xDA':
      {
         v = true;
         break;
      }
      case '\xDB':
      {
         v = true;
         break;
      }
      case '\xDC':
      {
         v = true;
         break;
      }
      case '\xE0':
      {
         v = true;
         break;
      }
      case '\xE1':
      {
         v = true;
         break;
      }
      case '\xE2':
      {
         v = true;
         break;
      }
      case '\xE3':
      {
         v = true;
         break;
      }
      case '\xE4':
      {
         v = true;
         break;
      }
      case '\xE5':
      {
         v = true;
         break;
      }
      case '\xE8':
      {
         v = true;
         break;
      }
      case '\xE9':
      {
         v = true;
         break;
      }
      case '\xEA':
      {
         v = true;
         break;
      }
      case '\xEB':
      {
         v = true;
         break;
      }
      case '\xEC':
      {
         v = true;
         break;
      }
      case '\xED':
      {
         v = true;
         break;
      }
      case '\xEE':
      {
         v = true;
         break;
      }
      case '\xEF':
      {
         v = true;
         break;
      }
      case '\xF2':
      {
         v = true;
         break;
      }
      case '\xF3':
      {
         v = true;
         break;
      }
      case '\xF4':
      {
         v = true;
         break;
      }
      case '\xF5':
      {
         v = true;
         break;
      }
      case '\xF6':
      {
         v = true;
         break;
      }
      case '\xF9':
      {
         v = true;
         break;
      }
      case '\xFA':
      {
         v = true;
         break;
      }
      case '\xFB':
      {
         v = true;
         break;
      }
      case '\xFC':
      {
         v = true;
         break;
      }
   }

   return v;
}

// There's a cat!
// Thr's  ct!

// sample solution was an in-place removal.  Here's one way to do that -- this time using std::string
//
// with optimization, this version is 91 instructions (299 bytes), whereas the C version was: 39 instructions (119 bytes)
//
// C++ costs us a lot of code size (C version is 40% the size of the C++ code.)
// 
void removevowels( std::string & s ) {

   size_t len = s.length();
   size_t nvpos = 0; // current non-vowel write position

   // A sliding window memmove, one character at a time.
   // If there are no vowels this does a useless copy of every character -- probably generally cheaper than checking each time if curpos = pos:
   for ( size_t i = 0 ; i < len ; i++ ) {
      if ( !isvowel( s[i] ) ) {
         s[nvpos] = s[i];
         nvpos++;
      }
   }
   s.resize(nvpos);
}

int main( int argc, char ** argv )
{
   std::string s{ "Hi there, how are \xFB\xE2you?" };
   removevowels( s );
   printf( "%s\n", s.c_str() );

   return 0;
}

// vim: et ts=3 sw=3 fileencoding=latin1
