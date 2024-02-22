#pragma once

#include <iostream>
#include <cstdlib>

template <typename T>
class Array {
	private:
		T * _array;
		size_t _size;
	public:
		Array();
		Array(unsigned int n);
		Array(Array const & src);
		~Array();
		Array & operator=(Array const & rhs);
		T &operator[](unsigned int n);
		size_t size();
		class OutofBoundException : public std::exception {
			public:
				virtual const char * what() const throw();
		};
};