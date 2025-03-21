#include <ranges>
#include <vector>
#include <iostream>
#include <format>

int main() {
#ifdef __cpp_lib_ranges_to_container
    auto v = std::views::iota( 0, 5 ) | std::ranges::to<std::vector>();
                                      | std::ranges::views::reverse // just for fun
                                      | std::ranges::to<std::vector>();
    std::ranges::sort( v );  // Sort back to ascending

    for ( int x : v ) {
        std::cout << std::format( "{} ", x );
    }
    std::cout << '\n';
    std::cout << "ranges::to supported, value: " << __cpp_lib_ranges_to_container << "\n";
#else
    std::cout << "ranges::to not supported\n";
#endif

    return 0;
}
