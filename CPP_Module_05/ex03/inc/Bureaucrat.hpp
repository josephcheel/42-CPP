#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <exception>
# include "AForm.hpp"

class AForm;

class Bureaucrat {

	protected:
		std::string const	_name;
		int					_grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		~Bureaucrat();

		Bureaucrat(Bureaucrat &copy);
		Bureaucrat &operator=(Bureaucrat const &copy);

		std::string	getName() const;
		int		getGrade() const;
		void		incrementGrade();
		void		decrementGrade();
		void	signForm(AForm &form);
		void	executeForm(AForm const &form);
		
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& stream, const Bureaucrat& copy);

#endif 
