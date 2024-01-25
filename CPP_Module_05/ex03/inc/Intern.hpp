#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern {

	public:
		Intern();
		~Intern();

		Intern(const Intern &copy);
		Intern &operator=(Intern const &copy);

		AForm *makeForm(std::string form_name, std::string target);
		class FormDoesNotExistException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

	private:
		std::array<std::string, 3> _form_names;
};

#endif