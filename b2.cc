#include <assert.h>
#include <stdio.h>
#include <bitset>

using long_type = long long;

int roundToNearestPowerOfTwo( int x, int & flips ) {
   int y = x;
   int ones = 0;
   flips = 0;

   if ( x == 0 ) {
      return x;
   }

   int lastright = 0;

   do {
      int rightmost = y & (y -1); // Hacker's delight, page 11: turn off rightmost bit.
      if ( rightmost ) {
         ones++;
         lastright = rightmost;
         y = rightmost;
      } else {
         break;
      }
   } while ( 1 );

   if ( ones == 0 ) {
      // there was only 1 bit set.  This is already a power of two (flips = 0)
      return x;
   }
   ones++;

   // lastright is now the rounded down to a power of two value.
   long_type up = lastright << 1;
   long_type distance_from_roundup = up - x;
   long_type distance_from_rounddown = x - lastright;
   if ( distance_from_roundup < distance_from_rounddown ) {
      flips = 1 + ones;
      assert( (up & 0x100000000) == 0 );
      return up;
   } else {
      flips = ones;
      return lastright;
   }
}

std::string tobinary( int x ) {
   return std::bitset< 32 >( x ).to_string();
}

int main()
{
   int a = 7;
   int aflips;

   int b = 13;
   int bflips;

#if 0
   for ( int i = 0 ; i < 16 ; i++ ) {
      int aprime = roundToNearestPowerOfTwo( i, aflips );
      printf( "%d (%s) -> %d (%s) [%d]\n", i, tobinary(i).c_str(), aprime, tobinary(aprime).c_str(), aflips );   
   }
#endif
   int aprime = roundToNearestPowerOfTwo( a, aflips );
   int bprime = roundToNearestPowerOfTwo( b, bflips );
   printf( "%d (%s) -> %d (%s)\n", a, tobinary(a).c_str(), aprime, tobinary(aprime).c_str() );   
   printf( "%d (%s) -> %d (%s)\n", b, tobinary(b).c_str(), bprime, tobinary(bprime).c_str() );   

   int shiftreq = 0;
   if ( bprime <= aprime ) {
   } else {
      for ( int i = bprime ; i > aprime ; i = i>>1 ) {
         shiftreq++; 
      }
   }
   printf( "shift req: %d\n", shiftreq );

   return 0;
}
