# include "../inc/Bureaucrat.hpp"
# include "../inc/AForm.hpp"
# include "../inc/PresidentialPardonForm.hpp"
# include "../inc/RobotomyRequestForm.hpp"
# include "../inc/ShrubberyCreationForm.hpp"
# include "../inc/Intern.hpp"
# include "../inc/Color.hpp"
# include <iostream>
int main()
{
	std::cout << "\n######################## CLASS FUNCTIONALITY ############################" << std::endl << std::endl;
	
	std::cout << "---------INTERN CLASS-----------" << std::endl << std::endl;
	{
		AForm *form;
		Intern Creator;
		Bureaucrat Bur("Bur", 1);

		std::cout << std::endl;
		form = Creator.makeForm("Presidential Pardon", "Me as a target");

		std::cout << std::endl;
		
		form->beSigned(Bur);
		form->execute(Bur);

		std::cout << std::endl;
	}
	std::cout << "---------INTERN CLASS EXCEPTIONS-----------" << std::endl << std::endl;
	{
		try
		{
			AForm *form;
			Intern Creator;
			Bureaucrat Bur("Bur", 1);

			std::cout << std::endl;
			form = Creator.makeForm("Does not Exist", "Me as a target");

			std::cout << std::endl;
			
			form->beSigned(Bur);
			form->execute(Bur);

			std::cout << std::endl;
		}
		catch (Intern::FormDoesNotExistException &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}
