#ifndef PHONE_BOOK_H
# define PHONE_BOOK_H
# include "Contact.class.hpp"

class PhoneBook {

private :
	Contact contacts[8];
	int nbr_contacts;
public:
	PhoneBook();
	~PhoneBook();
	void add_contact(void);
	void display_contact(void);
	void search_contact();
};
#endif