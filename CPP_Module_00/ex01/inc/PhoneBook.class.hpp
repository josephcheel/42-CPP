#ifndef PHONE_BOOK_H
# define PHONE_BOOK_H
# include "Contact.class.hpp"
# include <iostream>
class PhoneBook {

private :
	Contact contacts[8];
	int nbr_contacts;
public:
	PhoneBook();
	~PhoneBook();
	void add_contact(int oldest);
	void display_contact(void);
	void search_contact();
};
#endif