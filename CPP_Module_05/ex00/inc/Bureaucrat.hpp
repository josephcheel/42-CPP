#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class Bureaucrat {

	protected:
		std::string const	_name;
		int					_grade;
	public:
		Bureaucrat();
		
		Bureaucrat(std::string name, int grade);

		~Bureaucrat();

		Bureaucrat(Bureaucrat &copy);
		Bureaucrat const &operator=(Bureaucrat &copy);
		std::string	getName();
		int			getGrade();

};

#endif 