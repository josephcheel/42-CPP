# include "../inc/easyfind.hpp"

const char *IntergerNotFound::what() const throw()
{
	return ("[IntergerNotFound Exception]");
}

template<typename T>
typename T::iterator easyfind(T &container, int find)
{
	typename T::iterator i = std::find(container.begin(), container.end(), find);
	if (i == container.end())
		throw ::IntergerNotFound();
	return i;
}