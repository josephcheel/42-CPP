# include "../inc/Bureaucrat.hpp"

int main()
{
	std::cout << "------------CLASS BASICS---------------" << std::endl << std::endl;
	{
		//Default constructor
		Bureaucrat instance1;

		// Parameter constructor
		Bureaucrat instance2("me", 150);

		// Copy constructor
		Bureaucrat instance3(instance2);

		// Copy Assignment operator
		instance1 = instance2;
	
		// Overload of the insertion («) operator
		std::cout << instance1 << std::endl;
		std::cout << instance2 << std::endl;
		std::cout << instance1 << std::endl;
	}
	std::cout << std::endl << "-----------CLASS GETTERS--------------" << std::endl << std::endl;
	{
		Bureaucrat instance1("burrrrreeeacraat", 150);
		std::cout << "Name: " << instance1.getName() << std::endl;
		std::cout << "Grade: " << instance1.getGrade() << std::endl;
	}
	std::cout << std::endl << "-----------CLASS GETTERS--------------" << std::endl << std::endl;
	{
		Bureaucrat instance1("burrrrreeeacraat", 150);
		std::cout << "Name: " << instance1.getName() << std::endl;
		std::cout << "Grade: " << instance1.getGrade() << std::endl;
	}
	std::cout << std::endl << "-----------CLASS INCREMENT AND DECREMENT--------------" << std::endl << std::endl;
	{
		Bureaucrat instance1("burrrrreeeacraat", 150);
		std::cout << "Name: " << instance1.getName() << std::endl;
		std::cout << "Grade: " << instance1.getGrade() << std::endl;
		instance1.incrementGrade();
		instance1.incrementGrade();
		instance1.incrementGrade();
		std::cout << "Grade: " << instance1.getGrade() << std::endl;
		instance1.decrementGrade();
		std::cout << "Grade: " << instance1.getGrade() << std::endl;
	}
	std::cout << std::endl << "-----------CLASS EXCEPTION--------------" << std::endl << std::endl;
	try
	{
		// Constructor Exception Too Low
		Bureaucrat instance4("me", 152);
		// Constructor Exception Too High
		Bureaucrat instance5("me", 0);

		// Increment Exception Too High
		Bureaucrat instance6("me", 1);
		instance6.incrementGrade();

		// Decrement Exception Too Low
		Bureaucrat instance7("me", 150);
		instance7.decrementGrade();
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
