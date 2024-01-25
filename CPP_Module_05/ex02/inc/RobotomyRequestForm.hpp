#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP

# include "AForm.hpp"


class RobotomyRequestForm : public AForm{

	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		~RobotomyRequestForm();

		RobotomyRequestForm(const RobotomyRequestForm &copy);
		const RobotomyRequestForm &operator=(const RobotomyRequestForm &copy);
		void		execute(const Bureaucrat & executor ) const;
	private:
		const std::string _target;
};

#endif