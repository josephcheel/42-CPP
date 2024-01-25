# include "../inc/ShrubberyCreationForm.hpp"

// Required grades: sign 145, exec 137
// Create a file <target>_shrubbery in the working directory, and writes ASCII trees
// inside it

ShrubberyCreationForm::ShrubberyCreationForm() :
AForm("ShrubberyCreationForm", false, 145, 137),
_target("NoTarget")
{
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
AForm("ShrubberyCreationForm", false, 145, 137),
_target(target)
{
	std::cout << "ShrubberyCreationForm parameter constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy)
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
	*this = copy;
}

const ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
	std::cout << "ShrubberyCreationForm assignation operator called" << std::endl;
	(void)copy;
	return (*this);
}

void		ShrubberyCreationForm::execute(const Bureaucrat & executor ) const
{
	if (!canExecute(executor))
		return ;
	else
	{
		std::ofstream file;
		file.open(this->_target + "_shrubbery");
		file << "      /\\\n";
		file << "     /\\*\\\n";
		file << "    /\\O\\*\\\n";
		file << "   /*/\\/\\/\\\n";
		file << "  /\\O\\/\\*\\/\\\n";
		file << " /\\*\\/\\*\\/\\/\\\n";
		file << "/\\O\\/\\/*/\\/O/\\\n";
		file << "      ||\n";
		file << "      ||\n";
		file << "      ||\n";
		file << "    \\====/\n";
		file << "     \\__/\n";
		file << std::endl;
		file.close();
	}
}