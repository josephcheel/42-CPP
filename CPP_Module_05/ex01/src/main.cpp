# include "../inc/Bureaucrat.hpp"
# include "../inc/Form.hpp"
# include "../inc/Color.hpp"

int main()
{
	try
	{
		Bureaucrat Bureacrat1("1", 5);
		Form Form1("Form1", 0, 5, 0);
		Form Form2("Form2", 0, 7, 0);

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
