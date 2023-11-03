# include "../inc/Bureaucrat.hpp"

int main()
{
	try
	{
		// Bureaucrat instance1("me", 151);
		// Bureaucrat instance2("me", 0);
		Bureaucrat instance3("me", 150);
		std::cout << instance3 << std::endl;
		instance3.decrementGrade();
		std::cout << instance3 << std::endl;

	}
	catch(Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << '\n';
	}
	catch(Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}