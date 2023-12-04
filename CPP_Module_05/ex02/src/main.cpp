# include "../inc/Bureaucrat.hpp"
# include "../inc/Form.hpp"

// ANSI escape code to reset text color to the default
const char* RESET = "\033[0m";
// Define various text color escape codes
const char* BLACK = "\033[30m";
const char* RED = "\033[31m";
const char* GREEN = "\033[32m";
const char* YELLOW = "\033[33m";
const char* BLUE = "\033[34m";
const char* MAGENTA = "\033[35m";
const char* CYAN = "\033[36m";
const char* WHITE = "\033[37m";

int main()
{
	try
	{
		Bureaucrat Bureacrat1("1", 8);
		Form Form1("Form1", 0, 5, 0);
		Form Form2("Form2", 0, 5, 0);

		std::cout << GREEN << Form1 << RESET << std::endl;
		std::cout << BLUE << Form2 << RESET << std::endl;

		Bureacrat1.signForm(Form1);
		
		std::cout << GREEN << Form1 << RESET << std::endl;
		Form2.beSigned(Bureacrat1);
		std::cout << BLUE << Form2 << RESET << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << '\n';
	}
	catch(Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << '\n';
	}
	catch(Form::GradeTooLowException& e)
	{
		std::cerr << e.what() << '\n';
	}
	catch(Form::GradeTooHighException& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}
