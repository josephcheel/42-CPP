#include <iomanip>
#include <iostream>
#include <string>
#include "../inc/Contact.class.hpp"
#include "../inc/PhoneBook.class.hpp"

PhoneBook::PhoneBook(void)
{
	
	this->nbr_contacts = 0;
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

static bool isNumber(std::string str) {
  for (int i = 0; str[i]; i++) {
    if (std::isdigit(str[i]) == 0) 
		return false;
  }
  return true;
}

void	PhoneBook::add_contact(int oldest)
{
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone;
	std::string secret;

	std::cin.clear();
	std::cin.ignore(std::numeric_limits < std::streamsize>::max(), '\n');
	std::cout << "Enter First Name" << std::endl;
	while (first_name.length() == 0)
		getline(std::cin, first_name);
	std::cout << "Enter Last Name" << std::endl;
	while (last_name.length() == 0)
		getline(std::cin, last_name);
	std::cout << "Enter Nickname" << std::endl;
	while (nickname.length() == 0)
		getline(std::cin, nickname);
	std::cout << "Enter Phone Number" << std::endl;
	while (phone.length() == 0 || !isNumber(phone))
	{
		if (phone.length() != 0)
			std::cout << "Invalid Phone Number" << std::endl;
		getline(std::cin, phone);
	}
	std::cout << "Enter Darkest Secret" << std::endl;
	while (secret.length() == 0)
		getline(std::cin, secret);

	if (nbr_contacts == 8)
	{
		nbr_contacts = 7;
	}
	this->contacts[this->nbr_contacts].setFirstName(first_name);
	this->contacts[this->nbr_contacts].setLastName(last_name);
	this->contacts[this->nbr_contacts].setNickname(nickname);
	this->contacts[this->nbr_contacts].setPhoneNumber(phone);
	this->contacts[this->nbr_contacts].setDarkestSecret(secret);
	this->contacts[this->nbr_contacts].setOldest(oldest);
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
		std::cout << "First Name: " << this->contacts[selected - 1].getFirstName() << std::endl;
		std::cout << "Last Name: " << this->contacts[selected - 1].getLastName() << std::endl;
		std::cout << "Nickname: " << this->contacts[selected - 1].getNickname() << std::endl;
		std::cout << "Phone Number: " << this->contacts[selected - 1].getPhoneNumber() << std::endl;
		std::cout << "Darkest Secret: " << this->contacts[selected - 1].getDarkestSecret() << std::endl;
		std::cout << std::setw(10) << "--------------------------------" << std::endl;
	}
	else
		std::cout << "¡No contact match for index [" << selected << "]!" << std::endl << std::endl;
}

std::string	resize_string(std::string str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

void	PhoneBook::search_contact(void)
{
	// if (!this->nbr_contacts)
	// 	this->nbr_contacts = 0;
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
		std::cout << std::setw(10) << resize_string(this->contacts[i].getFirstName());
		std::cout << "|";
		std::cout << std::setw(10) << resize_string(this->contacts[i].getLastName());
		std::cout << "|";
		std::cout << std::setw(10) << resize_string(this->contacts[i].getNickname());
		std::cout << "|" << std::endl;;
	}
}