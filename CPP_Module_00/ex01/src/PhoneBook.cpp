#include <iomanip>
#include <iostream>
#include "../inc/Contact.class.hpp"
#include "../inc/PhoneBook.class.hpp"

// using namespace std;

PhoneBook::PhoneBook(void)
{
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

void	PhoneBook::add_contact()
{
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone;
	std::string secret;

	if (!this->nbr_contacts)
		this->nbr_contacts = 0;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits < std::streamsize>::max(), '\n');
	std::cout << "Enter First Name" << std::endl;
	getline(std::cin, first_name);
	std::cout << "Enter Last Name" << std::endl;
	getline(std::cin, last_name);
	std::cout << "Enter Nickname" << std::endl;
	getline(std::cin, nickname);
	std::cout << "Enter Phone Number" << std::endl;
	getline(std::cin, phone);
	std::cout << "Enter Darkest Secret" << std::endl;
	getline(std::cin, secret);

	if (nbr_contacts == 8)
		nbr_contacts = 7;
	this->contacts[this->nbr_contacts].first_name = first_name;
	this->contacts[this->nbr_contacts].last_name = last_name;
	this->contacts[this->nbr_contacts].nickname = nickname;
	this->contacts[this->nbr_contacts].phone_number = phone;
	this->contacts[this->nbr_contacts].darkest_secret = secret;
	this->nbr_contacts++;
}

void	PhoneBook::display_contact(void)
{
	int selected;


	std::cout << "Select Contact Index" << std::endl;
	std::cin >> selected;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	if (selected >= 1 && selected <= nbr_contacts)
	{
		std::cout << std::setw(10) << "--------------------------------" << std::endl;
		std::cout << "First Name: " << this->contacts[selected - 1].first_name << std::endl;
		std::cout << "Last Name: " << this->contacts[selected - 1].last_name << std::endl;
		std::cout << "Nickname: " << this->contacts[selected - 1].nickname << std::endl;
		std::cout << "Phone Number: " << this->contacts[selected - 1].phone_number << std::endl;
		std::cout << "Darkest Secret: " << this->contacts[selected - 1].darkest_secret << std::endl;
		std::cout << std::setw(10) << "--------------------------------" << std::endl;
	}
}

std::string	resize_string(std::string str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

void	PhoneBook::search_contact(void)
{
	std::cout << "|";
	std::cout << std::setw(10) << resize_string("Index");
	std::cout << "|";
	std::cout << std::setw(10) << resize_string("First Name");
	std::cout << "|";
	std::cout << std::setw(10) << resize_string("Last Name");
	std::cout << "|";
	std::cout << std::setw(10) << resize_string("Nickname");
	std::cout << "|" << std::endl;
	for(int i = 0; i < nbr_contacts; i++)
	{
		std::cout << "|";
		std::cout << std::setw(10) << i+1;
		std::cout << "|";
		std::cout << std::setw(10) << resize_string(this->contacts[i].first_name);
		std::cout << "|";
		std::cout << std::setw(10) << resize_string(this->contacts[i].last_name);
		std::cout << "|";
		std::cout << std::setw(10) << resize_string(this->contacts[i].nickname);
		std::cout << "|" << std::endl;;
	}
}