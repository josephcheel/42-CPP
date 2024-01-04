#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed {

	public :
		Fixed();
		Fixed(const Fixed &copy);
		Fixed &operator=(const Fixed &copy); 
		~Fixed();
		int getRawBits( void ) const;
		void setRawBits( int const raw );
	private :
		int _fixed_nbr;
		static const int _nbr_fract_bits = 8;
};

#endif