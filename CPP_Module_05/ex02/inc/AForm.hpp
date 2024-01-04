#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include "Bureaucrat.hpp"

class AForm {

	private:
		std::string const	_name;
		bool				_signed;
		const int			_gradeToSigned;
		const int 			_gradeToExecute;
	public: 
		AForm();
		AForm(std::string	name, bool	Signed, int	GradeToSigned, int	GradeToExecute);
		virtual ~AForm() = 0;

		AForm(AForm &copy);
		const AForm &operator=(const AForm &copy);

		void	beSigned(class Bureaucrat & B);

		std::string	getName() const;
		bool		getSigned() const;
		int			getGradeToSigned() const;
		int			getGradeToExecute() const;
		
	class GradeTooHighException {
		public:
			virtual const char* what() const throw() 
			{
				return ("GradeTooHighException: Grade Too High");
			}
	};

	class GradeTooLowException {
		public:
			virtual const char* what() const throw() 
			{
				return ("GradeTooHighException: Grade Too High");
			}
	};

};

std::ostream& operator<<(std::ostream& stream, const AForm& copy);

#endif
