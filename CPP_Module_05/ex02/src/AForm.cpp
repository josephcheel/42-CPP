#include "../inc/AForm.hpp"
#include "../inc/Bureaucrat.hpp"

AForm::AForm() : _name(""), _signed(false), _gradeToSigned(0), _gradeToExecute(0)
{
	std::cout << "Form default constructor called" << std::endl;
}
AForm::AForm(std::string	name, bool	Signed, int	GradeToSigned, int	GradeToExecute) :
_name(name),
_signed(Signed),
_gradeToSigned(GradeToSigned),
_gradeToExecute(GradeToExecute)
{
	std::cout << "Form constructor called" << std::endl;
}

AForm::~AForm()
{
	std::cout << "Form destructor called" << std::endl;
}

AForm::AForm(AForm &copy) :
_name(copy._name),
_signed(copy._signed),
_gradeToSigned(copy._gradeToSigned),
_gradeToExecute(copy._gradeToExecute)
{
	std::cout << "Form copy constructor called" << std::endl;
}

const AForm &AForm::operator=(const AForm &copy)
{
	(void)copy;
	return (*this);
}


void	AForm::beSigned(Bureaucrat &B)
{
	if (B.getGrade() <= this->_gradeToSigned)
		this->_signed = true;
	else if (B.getGrade() > this->_gradeToSigned)
		AForm::GradeTooLowException();
}

std::string	AForm::getName() const
{
	return (_name);
}

bool		AForm::getSigned() const
{
	return (_signed);
}
int			AForm::getGradeToSigned() const
{
	return (_gradeToSigned);
}
int			AForm::getGradeToExecute() const
{
	return (_gradeToExecute);
}

std::ostream& operator<<(std::ostream& stream, const AForm &copy)
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