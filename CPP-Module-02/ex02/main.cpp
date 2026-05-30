#include "Fixed.hpp"

int main( void ) 
{
Fixed a;
Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
std::cout << "Default: " << a << std::endl;
std::cout << "Pre-increment: " << ++a << std::endl;
std::cout << "After pre-increment: " << a << std::endl;
std::cout << "Post-increment: " << a++ << std::endl;
std::cout << "After post-increment: " << a << std::endl;
std::cout << "Fixed number created from 5.05f * 2: " << b << std::endl;
std::cout << "Previous number divided by 2: " << b / Fixed(2) << std::endl;
std::cout << "a - b: " << a - b << std::endl;
std::cout << "Max between a and b: " << Fixed::max( a, b ) << std::endl;
return 0;
}