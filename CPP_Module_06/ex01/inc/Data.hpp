#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>


class Data {
	private:
		char	c;
		int		i;
		float	f;
		double	d;
	public:
		Data();
		~Data();
		Data(Data const & src);
		Data &	operator=(Data const & copy);
		char	getChar() const;
		int		getInt()  const;
		float	getFloat()  const;
		double	getDouble()  const;
		void	setChar(char );
		void	setInt(int );
		void	setFloat(float );
		void	setDouble(double );
};

#endif
