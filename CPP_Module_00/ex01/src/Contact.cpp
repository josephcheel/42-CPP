#include "Contact.class.hpp"

std::string Contact::getFirstName()
{
	return (this->first_name);
}

std::string Contact::getLastName()
{
	return (this->last_name);
}

std::string Contact::getNickname()
{
	return (this->nickname);
}

std::string Contact::getPhoneNumber()
{
	return (this->phone_number);
}

std::string Contact::getDarkestSecret()
{
	return (this->darkest_secret);
}

int Contact::getOldest(void)
{
	return (this->oldest);
}

void Contact::setFirstName(std::string fn)
{
	this->first_name = fn;
}

void Contact::setLastName(std::string ln)
{
	this->last_name = ln;
}

void Contact::setNickname(std::string Nn)
{
	this->nickname = Nn;
}

void Contact::setPhoneNumber(std::string pn)
{
	this->phone_number = pn;
}

void Contact::setDarkestSecret(std::string ds)
{
	this->darkest_secret = ds;
}

void Contact::setOldest(int old)
{
	this->oldest = old;
}