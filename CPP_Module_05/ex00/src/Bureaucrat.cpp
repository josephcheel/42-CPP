#include "../inc/Bureaucrat.hpp"
#include "../inc/BureaucratGradeTooHighException.hpp"
#include "../inc/BureaucratGradeTooLowException.hpp"



Bureaucrat::Bureaucrat()
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
}
		
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	try
	{
		if (grade > 150)
			throw BureaucratGradeTooHighException();
		else if (grade < 1)
			throw BureaucratGradeTooLowException();
		else
			_grade(grade);
	} 
	catch (BureaucratGradeTooHighException& e) {
		 std::cerr << "Custom Exception: " << e.what() << std::endl;
	}
	catch (BureaucratGradeTooLowException& e) {
		 std::cerr << "Custom Exception: " << e.what() << std::endl;
	}
	std::cout << "Bureaucrat constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat &copy)
{

}
Bureaucrat const &Bureaucrat::operator=(Bureaucrat &copy)
{

}

std::string	Bureaucrat::getName()
{
	return (_name);
}

int			Bureaucrat::getGrade()
{
	return (_grade);
}