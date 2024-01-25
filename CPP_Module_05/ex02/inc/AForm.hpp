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
		virtual ~AForm();

		AForm(AForm &copy);
		const AForm &operator=(const AForm &copy);

		void	beSigned(class Bureaucrat & B);
		bool	canExecute(Bureaucrat const & executor) const;
		virtual void	execute(const Bureaucrat & executor) const = 0;

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
	class NotSignedException : public std::exception {
		public:
			virtual const char* what() const throw();
	};

};

std::ostream& operator<<(std::ostream& stream, const AForm& copy);

#endif
