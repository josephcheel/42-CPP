#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>

template<typename T>
typename T::iterator easyfind(T &container, int find);

class IntergerNotFound : public std::exception {
	public:
		virtual const char * what() const throw();
};

#endif
