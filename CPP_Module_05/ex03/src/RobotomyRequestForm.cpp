# include "../inc/RobotomyRequestForm.hpp"

// Required grades: sign 72, exec 45
// Makes some drilling noises. Then, informs that <target> has been robotomized
// successfully 50% of the time. Otherwise, informs that the robotomy failed.s

RobotomyRequestForm::RobotomyRequestForm() : 
AForm("RobotomyRequestForm", false, 72, 45),
_target("NoTarget")
{
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : 
AForm("RobotomyRequestForm", false, 72, 45),
_target(target)
{
	std::cout << "RobotomyRequestForm parameter constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy)
{
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
	*this = copy;
}

const RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
	std::cout << "RobotomyRequestForm assignation operator called" << std::endl;
	(void)copy;
	return (*this);
}

void	RobotomyRequestForm::execute(const Bureaucrat  &executor) const
{
	if (!canExecute(executor))
		return ;
	else
	{
		std::cout << this->_target << " is making some drilling noises! Crack Crack Crack..." << std::endl;
		
		int random = std::rand() % 2;
		if (random == 0)
			std::cout << this->_target << " has been robotomized successfully" << std::endl;
		else
			std::cout << this->_target << " robotomization failed" << std::endl;
	}
}