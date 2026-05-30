#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int value;
		static const int fract_bits;
	public:
		Fixed();
		Fixed(const Fixed &copy);
		Fixed(const int value);
		Fixed(const float value);
		Fixed &operator=(const Fixed &copy);
		bool operator>(const Fixed &other) const;
		bool operator<(const Fixed &other) const;
		bool operator>=(const Fixed &other) const;
		bool operator<=(const Fixed &other) const;
		bool operator==(const Fixed &other) const;
		bool operator!=(const Fixed &other) const;
		Fixed operator+(const Fixed &copy) const;
		Fixed operator-(const Fixed &copy) const;
		Fixed operator*(const Fixed &copy) const;
		Fixed operator/(const Fixed &copy) const;
		Fixed &operator++();
		Fixed operator++(int);
		Fixed &operator--();
		Fixed operator--(int);
		~Fixed();
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
		static Fixed &min(Fixed &first, Fixed &second);
		static const Fixed &min(const Fixed &first, const Fixed &second);
		static Fixed &max(Fixed &first, Fixed &second);
		static const Fixed &max(const Fixed &first, const Fixed &second);
};

std::ostream &operator<<(std::ostream& out, const Fixed &fixed);
