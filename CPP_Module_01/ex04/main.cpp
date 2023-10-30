#include <iostream>
#include <fstream>

int ft_usage( void )
{
	std::cout << "Usage: ./replacer.out <filename> <str1> <str2>" << std::endl;
	std::cout << "   - filename: The name of the file in which replacements will be made." << std::endl;
	std::cout << "   - str1:     The string to be replaced within the file." << std::endl;
	std::cout << "   - str2:     The string that will replace occurrences of str1 in the file." << std::endl;
	return 1;
}

std::string ft_replace(std::string line, std::string s1, std::string s2)
{
	size_t found = 0;

	while (found != std::string::npos)
	{
		found = line.find(s1, found);
		if (found != std::string::npos)
		{
			line.erase(found, s1.length());
			line.insert(found, s2);
			found += s2.length();
		}
	}
	return (line);
}

int main(int ac, char **av)
{
	if (ac != 4)
		return (ft_usage());

	std::string filename = av[1];
	std::string s1 = av[2]; 
	std::string s2 = av[3];

	std::string line;
	std::string result;
	
	// Opening file with <filename>
	std::ifstream inFile(filename);
	if (!inFile.is_open())
	{
		std::cout << "File Error" << std::endl;
		return 1;
	}

	// Creates the <filename>.replace 
	std::ofstream outFile(filename + ".replace");
	if (!outFile.is_open())
	{
		std::cout << "File Error" << std::endl;
		inFile.close();
		return 1;
	}
	
	// Loop to get line by line and replace <s1> for <s2>
	while (std::getline(inFile, line))
	{	
		result = ft_replace(line, s1, s2);
    	outFile << result << "\n";
	}		
	// Close Files
	outFile.close();
	inFile.close();

	return 0;
}	
