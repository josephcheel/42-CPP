#pragma once

# include "../inc/Array.hpp"

# include <iostream>

template <typename T>
Array<T>::Array()
{
	std::cout << "Array constructor called" << std::endl;
	_array = new T;
	_size = 0;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	std::cout << "Array parameter constructor called" << std::endl;
	_array = new T[n];
	_size = n;
}

template <typename T>
Array<T>::~Array()
{
	std::cout << "Array destructor called" << std::endl;
	delete _array;
}

template <typename T>
Array<T>&Array<T>::operator=(Array const & rhs)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != &rhs)
	{
		delete [] _array;
		_array = new T[rhs._size];
		for (size_t i = 0; i < rhs._size; i++)
			_array[i] = rhs._array[i];
		_size = rhs._size;
	}
	return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int n)
{
	if (n >= _size)
		throw OutofBoundException();
	return (_array[n]);
}

template <typename T>
Array<T>::Array(const Array & copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

template <typename T>
size_t Array<T>::size()
{
	return (_size);
}

template <typename T>
const char * Array<T>::OutofBoundException::what() const throw()
{
	return ("[OutofBoundException]:Out of bound");
}