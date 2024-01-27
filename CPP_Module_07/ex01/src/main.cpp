# include "../inc/Iter.hpp"
# include <iostream>

template <typename T>
void print(T a)
{
	std::cout << a << std::endl;
}

int main(void)
{
	int a[5] = {1, 2, 3, 4, 5};
	::iter<int, 5, print>(a);

	std::string b[5] = {"One", "Two", "Three", "Four", "Five"};
	::iter<std::string, 5, print>(b);

	float c[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
	::iter<float, 5, print>(c);
	return 0;

}