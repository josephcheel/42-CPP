# include "../inc/Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}

Intern::Intern(const Intern &copy)
{
	std::cout << "Intern copy constructor called" << std::endl;
	*this = copy;
}

Intern &Intern::operator=(const Intern &copy)
{
	std::cout << "Intern assignation operator called" << std::endl;
	(void)copy;
	return (*this);
}

std::string stringLower(std::string str)
{
	for (int c = 0; c < int(str.length()); c++)
	{
		if (std::isupper(str[c]))
			str[c] = char(std::tolower(str[c]));
	}
	return (str);
}


AForm	*Intern::makeForm(std::string form_name, std::string target)
{	
	AForm	*form;
	int i = -1;

	_form_names[0] = "robotomy request";
	_form_names[1] = "presidential pardon";
	_form_names[2] = "shrubbery creation";

	while (i++ < 3)
	{
		if (stringLower(form_name) == _form_names[i])
			break;
	}
	switch (i)
	{
		case 0:
			form = new RobotomyRequestForm(target);
			std::cout << "Intern creates " << form_name << std::endl;
			break;
		case 1:
			form = new PresidentialPardonForm(target);
			std::cout << "Intern creates " << form_name << std::endl;
			break;
		case 2:
			form = new ShrubberyCreationForm(target);
			std::cout << "Intern creates " << form_name << std::endl;
			break;
		default:
			form = NULL;
			throw Intern::FormDoesNotExistException();
			break;
	}
	return (form);
}

const char * Intern::FormDoesNotExistException::what() const throw()
{
	return("[FormDoesNotExistExceptio]Intern cannot create");
}