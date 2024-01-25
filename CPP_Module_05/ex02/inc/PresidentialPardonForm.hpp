#ifndef PRESIDENTIAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP

# include "AForm.hpp"

class AForm;

class PresidentialPardonForm : public AForm{

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string &target);
		~PresidentialPardonForm();

		PresidentialPardonForm(PresidentialPardonForm &copy);
		const PresidentialPardonForm &operator=(const PresidentialPardonForm &copy);
		void		execute(const Bureaucrat & executor ) const;
		
	private:
		const std::string _target;
};

#endif