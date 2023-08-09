#include <iostream>
#include <fstream>

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
	std::string line;
	std::string result;
	std::string s1 = av[2]; 
	std::string s2 = av[3];
	std::string filename = av[1];
	if (ac != 4)
		return 0;
	
	std::ifstream inFile(filename);
	if (!inFile.is_open())
	{
		std::cout << "File Error" << std::endl;
		return 1;
	}
	std::ofstream outFile(filename + ".replace");
	if (!outFile.is_open())
	{
		std::cout << "File Error" << std::endl;
		inFile.close();
		return 1;
	}
	
	while (std::getline(inFile, line))
	{	
		result = ft_replace(line, s1, s2);
    	outFile << result << "\n";
	}		
	outFile.close();
	inFile.close();
	return 0;
}	