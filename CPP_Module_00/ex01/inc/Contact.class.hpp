#ifndef CONTACT_H
# define CONTACT_H
# include <iostream>

class Contact {
	private :
		std::string first_name;
		std::string last_name; 
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;
		int	oldest;
	public	:

		std::string getFirstName(void);
		std::string getLastName(void);
		std::string getNickname(void);
		std::string getPhoneNumber(void);
		std::string getDarkestSecret(void);
		int getOldest(void);
		void setFirstName(std::string fn);
		void setLastName(std::string ln);
		void setNickname(std::string Nn);
		void setPhoneNumber(std::string pn);
		void setDarkestSecret(std::string ds);
		void setOldest(int old);
};
#endif