#pragma once
# include <iostream>

template<typename T>
void	iter(T Array[], unsigned int len, void (*f)(T&))
{
	for(unsigned int i = 0; i < len; i++)
		f(Array[i]);
}

template <typename T>
void print(T a)
{
	std::cout << a << std::endl;
}
