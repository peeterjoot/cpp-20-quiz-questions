// https://www.geeksforgeeks.org/cpp-coding-interview-questions-and-answers/
// 20. Write a Program to Calculate the Greatest Common Divisor of Two Numbers
#include <getopt.h>
#include <iostream>
#include <format>
#include <vector>
#include <algorithm>

using divisor_type = std::vector<int>;

static inline void collect_divisors( divisor_type & set, int abs_value ) {
    set.push_back( 1 );

    for ( int i = 2 ; i < abs_value ; i++ ) {
        if ( (abs_value % i) == 0 ) {
            set.push_back( i );
        } 
    }

    set.push_back( abs_value );
}

int gcd( int a, int b ) {
    int abs_a = std::abs( a );
    int abs_b = std::abs( b );
    divisor_type a_divisors;
    divisor_type b_divisors;

    collect_divisors( a_divisors, abs_a );
    collect_divisors( b_divisors, abs_b );

    std::vector<int> intersection;
    // set intersection can't be bigger than smallest of the two sets:
    intersection.reserve( std::min( a_divisors.size(), b_divisors.size() ) );

    set_intersection( a_divisors.begin(), a_divisors.end(),
                      b_divisors.begin(), b_divisors.end(),
                      std::back_inserter(intersection) ); // can't use intersection.begin() because there are no elements yet.
    
    return intersection.back();
}

int main(int argc, char *argv[]) {
    int opt{};
    struct option long_options[] = {
        {"a", required_argument, 0, 'a'},  
        {"b", required_argument, 0, 'b'},  
        {"csv", no_argument, 0, 'c'},  
        {0, 0, 0, 0}                       
    };

    int a{};
    int b{};
    bool csv{};
    while ((opt = getopt_long(argc, argv, "a:b:c", long_options, NULL)) != -1) {
        switch (opt) {
            case 'a':
                a = std::stoi( optarg );
                break;
            case 'b':
                b = std::stoi( optarg );
                break;
            case 'c':
                csv = true;
                break;
            case '?':
                return 1;
            default:
                std::cerr << "Bad option.\n";
                return 1;
        }
    }

    int g = gcd( a, b );
    if ( csv ) {
        std::cout << std::format( "{},{},{}\n", a, b, g );
    } else {
        std::cout << std::format( "gcd({},{}) = {}\n", a, b, g );
    }

    return 0;
}
