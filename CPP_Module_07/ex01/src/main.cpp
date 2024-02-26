# include "../inc/Iter.hpp"




int main(void)
{
	int a[5] = {1, 2, 3, 4, 5};
	::iter(a, 5, print);

	std::string b[5] = {"One", "Two", "Three", "Four", "Five"};
	::iter(b, 5, print);

	float c[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
	::iter(c, 5, print);
	return 0;

}