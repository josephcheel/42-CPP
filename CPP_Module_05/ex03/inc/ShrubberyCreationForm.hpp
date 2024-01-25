#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP

# include "AForm.hpp"
# include <fstream>

class ShrubberyCreationForm : public AForm{

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		~ShrubberyCreationForm();

		ShrubberyCreationForm(const ShrubberyCreationForm &copy);
		const ShrubberyCreationForm &operator=(const ShrubberyCreationForm &copy);
		void		execute(const Bureaucrat & executor ) const;
	private:
		const std::string _target;
};

#endif