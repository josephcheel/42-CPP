#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed {

	public :
		Fixed();
		Fixed(const Fixed &copy);
		Fixed(const int fixed_nbr);
		Fixed(const float float_nbr);
		~Fixed();

		Fixed	&operator=(const Fixed &copy);

		bool	operator>(const Fixed &f2); 
		bool	operator<(const Fixed &f2); 
		bool	operator>=(const Fixed &f2); 
		bool	operator<=(const Fixed &f2); 
		bool	operator==(const Fixed &f2);
		bool	operator!=(const Fixed &f2);
		
		float		operator+(const Fixed &f2);
		float		operator-(const Fixed &f2);
		float		operator*(const Fixed &f2);
		float		operator/(const Fixed &f2);

		Fixed	operator++(int);
		Fixed	operator++();
		Fixed	operator--(int);
		Fixed	operator--();

		static Fixed min(Fixed &f1, Fixed &f2);
		static Fixed const min(Fixed const &f1, Fixed const &f2);
		static Fixed max(Fixed &f1, Fixed &f2);
		static Fixed const max(Fixed const &f1, Fixed const &f2);

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;

	private :
		int		_fixed_nbr;
		static const int _nbr_fract_bits = 8;
};

std::ostream	& operator<<(std::ostream &ostream,  const Fixed &fixed_nbr); 
#endif