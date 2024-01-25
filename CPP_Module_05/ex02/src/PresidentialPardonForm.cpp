# include "../inc/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : 
AForm("PresidentialPardonForm", false, 25, 5),
_target("NoTargets")
{
	std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string &target)  : 
AForm("PresidentialPardonForm", false, 25, 5),
_target(target)
{
	std::cout << "PresidentialPardonForm parameter constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &copy)
{
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
	*this = copy;
}

const PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
	std::cout << "PresidentialPardonForm assignation operator called" << std::endl;
	(void)copy;
	return (*this);
}

void	PresidentialPardonForm::execute(const Bureaucrat  &executor) const
{
	if (canExecute(executor))
		return ;
	else
		std::cout << this->_target << " has been pardoned by  Zaphod Beeblebrox" << std::endl;
	
}