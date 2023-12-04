#include <iomanip>
#include <iostream>
#include "../inc/PhoneBook.class.hpp"

int	main(void)
{
	std::string input;
	static int	oldest = 0;
	std::cout << std::setw(10) << "--------------------------------" << std::endl;
	std::cout << "My Awesome PhoneBook is started" << std::endl;
	std::cout << std::setw(10) << "--------------------------------" << std::endl;
	PhoneBook phonebook;
	while (1) 
	{
		std::cout << "Enter ADD, SEARCH or EXIT" << std::endl;
		std::cin >> input;
		if (input == "ADD")
			phonebook.add_contact(oldest);
		else if(input == "SEARCH")
		{
			phonebook.search_contact();
			phonebook.display_contact();
		}
		else if (input == "EXIT")
			break;
	}
	return (0);
}
