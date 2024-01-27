#include "../inc/Serializer.hpp"

Serializer::Serializer(void)
{
	std::cout << "Serializer Default constructor called" << std::endl;
}


Serializer::Serializer(Serializer const & src)
{
	std::cout << "Serializer Copy constructor called" << std::endl;
	*this = src;
}

Serializer::~Serializer(void)
{
	std::cout << "Serializer Destructor called" << std::endl;
}

Serializer &Serializer::operator=(Serializer const & copy)
{
	std::cout << "Serializer Assignation operator called" << std::endl;
	(void)copy;
	return (*this);
}

uintptr_t	Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*	Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}