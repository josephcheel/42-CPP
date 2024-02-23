#include "../inc/easyfind.tpp"
#include <iostream>
#include <vector>
#include <list>

int main(void)
{
	std::list<int> a;
	a.push_back(24);
	a.push_back(42);
	a.push_back(30);
	a.push_back(2);
	a.push_back(45);
	// = {24, 42, 30, 2, 45};

	std::cout << *easyfind(a, 2) << std::endl;

	std::vector<int> v;
	v.push_back(24);
	v.push_back(42);
	v.push_back(30);
	v.push_back(2);
	v.push_back(45);
	std::cout << *easyfind(v, 42) << std::endl;
	try
	{
		std::vector<int> v;
		v.push_back(24);
		v.push_back(42);
		v.push_back(30);
		v.push_back(2);
		v.push_back(45);
		std::cout << *easyfind(v, 1313) << std::endl;	
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}