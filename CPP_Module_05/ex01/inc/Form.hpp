#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include "Bureaucrat.hpp"

class Form {

	private:
		std::string const	_name;
		bool				_signed;
		const int			_gradeToSigned;
		const int 			_gradeToExecute;
	public: 
		Form();
		Form(std::string	name, bool	Signed, int	GradeToSigned, int	GradeToExecute);
		~Form();

		Form(Form &copy);
		const Form &operator=(const Form &copy);

		void	beSigned(class Bureaucrat & B);

		std::string	getName() const;
		bool		getSigned() const;
		int			getGradeToSigned() const;
		int			getGradeToExecute() const;
		
	class GradeTooHighException : public std::exception {
		public:
			virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
		public:
			virtual const char* what() const throw();
	};

};

std::ostream& operator<<(std::ostream& stream, const Form& copy);

#endif
