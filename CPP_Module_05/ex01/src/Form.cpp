#include "../inc/Form.hpp"
#include "../inc/Bureaucrat.hpp"

Form::Form() : _name(""), _signed(false), _gradeToSigned(0), _gradeToExecute(0)
{
	std::cout << "Form default constructor called" << std::endl;
}
Form::Form(std::string	name, bool	Signed, int	GradeToSigned, int	GradeToExecute) :
_name(name),
_signed(Signed),
_gradeToSigned(GradeToSigned),
_gradeToExecute(GradeToExecute)
{
	std::cout << "Form constructor called" << std::endl;
}

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}

Form::Form(Form &copy) :
_name(copy._name),
_signed(copy._signed),
_gradeToSigned(copy._gradeToSigned),
_gradeToExecute(copy._gradeToExecute)
{
	std::cout << "Form copy constructor called" << std::endl;
}

const Form &Form::operator=(const Form &copy)
{
	(void)copy;
	return (*this);
}

void	Form::beSigned(Bureaucrat &B)
{
	if (B.getGrade() <= this->_gradeToSigned)
		this->_signed = true;
	else if (B.getGrade() > this->_gradeToSigned)
		throw Form::GradeTooLowException();
}

std::string	Form::getName() const
{
	return (_name);
}

bool		Form::getSigned() const
{
	return (_signed);
}
int			Form::getGradeToSigned() const
{
	return (_gradeToSigned);
}
int			Form::getGradeToExecute() const
{
	return (_gradeToExecute);
}

std::ostream& operator<<(std::ostream& stream, const Form &copy)
{
	stream << "Form object named " << copy.getName();
	if (copy.getSigned() == true)
		stream << " is signed." << std::endl;
	else
		stream << " is not signed." << std::endl;
	stream << "Grade to Signed: " << copy.getGradeToSigned();
	stream << ". Grade to Execute: " << copy.getGradeToExecute();
	return (stream); 
}