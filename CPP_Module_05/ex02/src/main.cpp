# include "../inc/Bureaucrat.hpp"
# include "../inc/AForm.hpp"
# include "../inc/PresidentialPardonForm.hpp"
# include "../inc/RobotomyRequestForm.hpp"
# include "../inc/ShrubberyCreationForm.hpp"
# include "../inc/Color.hpp"
# include <iostream>
int main()
{
	std::cout << "\n######################## CLASS FUNCTIONALITY ############################" << std::endl << std::endl;
	
	std::cout << "---------AFORM CLASS-----------" << std::endl << std::endl;
	{
		// Abstract class Can't be Initialized
		
		// AForm example;
		// AForm Form1("Form1", false, 5, 5);

	}
	std::cout << "---------PRESIDENTIAL PARDON FORM CLASS-----------" << std::endl << std::endl;
	{
		// Required grades: sign 25, exec 5
		// Informs that <target> has been pardoned by Zaphod Beeblebrox.
		Bureaucrat Bur("Bur", 1);
		PresidentialPardonForm example("example");
		
		std::cout << std::endl;

		example.beSigned(Bur);
		example.execute(Bur);

	}
	std::cout << "---------ROBOTOMY REQUEST FORM CLASS-----------" << std::endl << std::endl;
	{
		// Required grades: sign 72, exec 45
		// Makes some drilling noises. Then, informs that <target> has been robotomized
		// successfully 50% of the time. Otherwise, informs that the robotomy failed.s
		Bureaucrat Bur("Bur", 1);
		RobotomyRequestForm example("example");


		std::cout << std::endl;

		example.beSigned(Bur);
		example.execute(Bur);

		example.execute(Bur);
		example.execute(Bur);
		example.execute(Bur);
		example.execute(Bur);
		example.execute(Bur);
		example.execute(Bur);
		example.execute(Bur);

	}
	std::cout << "---------SHRUBBERY CREATION FORM CLASS-----------" << std::endl << std::endl;
	{
		// Required grades: sign 145, exec 137
		// Create a file <target>_shrubbery in the working directory, and writes ASCII trees
		// inside it
		Bureaucrat Bur("Bur", 1);
		ShrubberyCreationForm example("example");

		std::cout << std::endl;

		example.beSigned(Bur);
		example.execute(Bur);
		
	}
	std::cout << "---------BUREAUCRAT CLASS-----------" << std::endl << std::endl;
	{
		Bureaucrat Bur("Bur", 1);
		PresidentialPardonForm Form("TestForm");

		std::cout << std::endl;
		
		Form.beSigned(Bur);
		Bur.executeForm(Form); // executeForm() calls execute() from the form

		std::cout << std::endl;
	}

	std::cout << "---------AFORM CLASS EXCEPTIONS-----------" << std::endl << std::endl;
	{
		
		try 
		{
			PresidentialPardonForm FormEx("FormEx");
		}
		catch (AForm::GradeTooLowException &e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	std::cout << "\n######################## EXCEPTIONS ############################" << std::endl << std::endl;
	
	std::cout << "---------PRESIDENTIAL PARDON FORM CLASS EXCEPTIONS-----------" << std::endl << std::endl;
	{
		// Required grades: sign 25, exec 5
		// Informs that <target> has been pardoned by Zaphod Beeblebrox.
		
		try
		{
			Bureaucrat Bur("Bur", 5);
			PresidentialPardonForm FormEx("FormEx");

			std::cout << std::endl;

			FormEx.execute(Bur); // Not Signed
		}
		catch (AForm::NotSignedException &e)
		{
			std::cerr << e.what() << '\n';
		}

		try
		{
			Bureaucrat Bur("Bur", 6);
			PresidentialPardonForm FormEx("FormEx");

			std::cout << std::endl;

			FormEx.beSigned(Bur);
			FormEx.execute(Bur); // Grade Too Low
		}
		catch (AForm::GradeTooLowException &e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	std::cout << "---------ROBOTOMY REQUEST FORM CLASS EXCEPTIONS-----------" << std::endl << std::endl;
	{
		// Required grades: sign 72, exec 45
		// Makes some drilling noises. Then, informs that <target> has been robotomized
		// successfully 50% of the time. Otherwise, informs that the robotomy failed.

		try
		{
			Bureaucrat Bur("Bur", 45);
			RobotomyRequestForm FormEx("FormEx");

			std::cout << std::endl;

			FormEx.execute(Bur); // Not Signed
		}
		catch (AForm::NotSignedException &e)
		{
			std::cerr << e.what() << '\n';
		}

		try
		{
			Bureaucrat Bur("Bur", 46);
			RobotomyRequestForm FormEx("FormEx");

			std::cout << std::endl;

			FormEx.execute(Bur); // Grade Too Low
		}
		catch (AForm::NotSignedException &e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	std::cout << "---------SHRUBBERY CREATION FORM CLASS EXCEPTIONS-----------" << std::endl << std::endl;
	{
		// Required grades: sign 145, exec 137
		// Create a file <target>_shrubbery in the working directory, and writes ASCII trees
		// inside it

				try
		{
			Bureaucrat Bur("Bur", 45);
			ShrubberyCreationForm FormEx("FormEx");

			std::cout << std::endl;

			FormEx.execute(Bur); // Not Signed
		}
		catch (AForm::NotSignedException &e)
		{
			std::cerr << e.what() << '\n';
		}

		std::cout << std::endl;
		try
		{
			Bureaucrat Bur("Bur", 46);
			ShrubberyCreationForm FormEx("FormEx");

			std::cout << std::endl;

			FormEx.execute(Bur); // Grade Too Low
		}
		catch (AForm::NotSignedException &e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	std::cout << "---------BUREAUCRAT CLASS EXCEPTIONS-----------" << std::endl << std::endl;
	{
		try 
		{
			Bureaucrat Bur("Bur", 1);
			RobotomyRequestForm example("example");

			std::cout << std::endl;

			Bur.executeForm(example); // Not Signed
		}
		catch (AForm::NotSignedException &e)
		{
			std::cerr << e.what() << '\n';
		}

		std::cout << std::endl;
		try 
		{
			Bureaucrat Bur("Bur", 46);
			RobotomyRequestForm example("example");

			std::cout << std::endl;

			example.beSigned(Bur);
			Bur.executeForm(example); // Grade Too Low
		}
		catch (AForm::GradeTooLowException &e)
		{
			std::cerr << e.what() << '\n';
		}
	}
}
