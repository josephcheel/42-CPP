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
