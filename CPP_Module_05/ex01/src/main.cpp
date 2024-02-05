# include "../inc/Bureaucrat.hpp"
# include "../inc/Form.hpp"
# include "../inc/Color.hpp"

int main()
{
	std::cout << "------------CLASS BASICS---------------" << std::endl << std::endl;
	{
		//Default constructor
		Form instance1;

		// Parameter constructor
		Form instance2("me", false, 10, 5);

		// Copy constructor
		Form instance3(instance2);

		// Copy Assignment operator
		instance1 = instance2;
	
		// Overload of the insertion («) operator
		std::cout << instance1 << std::endl;
		std::cout << instance2 << std::endl;
		std::cout << instance1 << std::endl;
	}
	std::cout << std::endl << "-----------CLASS GETTERS--------------" << std::endl << std::endl;
	{
		Form instance1("Fooorm", false, 10, 5);
		std::cout << "Name: " << instance1.getName() << std::endl;
		std::cout << "is Signed:\t\t" << std::boolalpha << instance1.getSigned() << std::endl;
		std::cout << "Grade to Sign:\t\t" << instance1.getGradeToSigned() << std::endl;
		std::cout << "Grade to Execute:\t" << instance1.getGradeToExecute() << std::endl;
	}
	std::cout << std::endl << "-----------CLASS beSigned()--------------" << std::endl << std::endl;
	{
		Form instance1("BURRR", false, 10, 5);
		Bureaucrat Bur("me", 10);

		std::cout << BLUE << instance1 << RESET << std::endl;
		std::cout << GREEN << Bur << RESET << std::endl;
		instance1.beSigned(Bur);
		std::cout << BLUE << instance1 << RESET << std::endl;
	}
	std::cout << std::endl << "-----------FORM CLASS EXCEPTIONS--------------" << std::endl << std::endl;
	{
		try
		{
			// Constructor Exception Too Low
			Form instance("me", false, 152, 5);
			// Constructor Exception Too High
			Form instance2("me", false, 0, 5);

			// Signed Too Low Exception
			Bureaucrat Bur("me", 10);
			Form instance3("me", false, 1, 5);
			instance3.beSigned(Bur);
		}
		catch(Form::GradeTooHighException& e)
		{
			std::cerr << e.what() << '\n';
		}
		catch(Form::GradeTooLowException& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	std::cout << std::endl << "-----------BUREACRAT CLASS signForm()--------------" << std::endl << std::endl;
	{
		try
		{
			// Simple Sign
			Bureaucrat Bur("SimpleBur", 10);
			Form instance("SuperForm", false, 10, 5);
			std::cout << BLUE << instance << RESET << std::endl;
			Bur.signForm(instance);
			std::cout << GREEN << instance << RESET << std::endl;

			// Simple Sign Grade Too Low
			Bureaucrat Bur2("SimpleBur", 10);
			Form instance2("SuperForm", false, 5, 5);
			std::cout << BLUE << instance2 << RESET << std::endl;
			Bur2.signForm(instance2);
			std::cout << GREEN << instance2 << RESET << std::endl;
			
		}
		catch(Form::GradeTooLowException& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	
}
