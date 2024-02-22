# include "../inc/Data.hpp"

Data::Data()
{
	std::cout << "Data Default constructor called" << std::endl;
}

Data::Data(Data const & src)
{
	std::cout << "Data Copy constructor called" << std::endl;
	*this = src;
}

Data::~Data()
{
	std::cout << "Data Destructor called" << std::endl;
}

Data &Data::operator=(Data const & copy)
{
	std::cout << "Data Assignation operator called" << std::endl;
	if (this != &copy)
	{
		this->c = copy.c;
		this->i = copy.i;
		this->f = copy.f;
		this->d = copy.d;
	}
	return (*this);
}

char	Data::getChar() const
{
	return (c);
}
int		Data::getInt()  const
{
	return (i);
}
float	Data::getFloat()  const
{
	return (f);
}
double	Data::getDouble()  const
{
	return (d);
}

void	Data::setChar(char c)
{
	this->c = c;
}

void	Data::setInt(int i)
{
	this->i = i;
}

void	Data::setFloat(float f)
{
	this->f = f;
}

void	Data::setDouble(double d)
{
	this->d = d;
}