#include "../inc/Form.hpp"
#include "../inc/Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
}
		
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else
	{
		std::cout << "Bureaucrat constructor called" << std::endl;
		this->_grade = grade;
	}
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat &copy) : _name(copy._name), _grade( copy._grade)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &copy)
{
	if (this != &copy)
	{
		// _name = copy.getName();
		_grade = copy.getGrade();
	}
	return (*this);
}

std::string 	Bureaucrat::getName() const
{
	return (_name);
}

int			Bureaucrat::getGrade() const
{
	return (_grade);
}

void	Bureaucrat::incrementGrade()
{
	if (this->_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade--;
}	
	
void	Bureaucrat::decrementGrade()
{
	if (this->_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade++;
}

std::ostream &operator<<(std::ostream& stream, const Bureaucrat &copy)
{
	stream << copy.getName() <<" , bureaucrat grade " << copy.getGrade();
	return (stream); 
}

void	Bureaucrat::signForm(Form &form)
{
	if (form.getGradeToSigned() >= this->getGrade())
	{
		std::cout << this->getName() << " signed " <<  form.getName() << std::endl;
		form.beSigned(*this);
	}
	else
	{
		std::cout << this->getName() << " couldn’t sign " <<  form.getName() << " because Grade is too low" << std::endl;
		throw Form::GradeTooLowException();
	}
}
