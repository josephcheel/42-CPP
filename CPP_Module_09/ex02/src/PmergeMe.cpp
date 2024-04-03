# include "../inc/PmergeMe.hpp"

/* Constructor & Destructor */
PmergeMe::PmergeMe()
{
	std::cout << "PmergeMe Default Constructor called" << std::endl;
}

PmergeMe::~PmergeMe()
{
	std::cout << "PmergeMe Destructor called" << std::endl;
}

/* Checker */
static bool isNumber(std::string str)
{
	size_t start = 0;
	
	if (str[start] == '+' || str[start] == '-')
		start = 1;
	if (start == str.size())
		return false;
	for (size_t i = start; i < str.length(); ++i)
	{
		if (!std::isdigit(str[i])) 
			return false;
	}
	return true;
}

bool	PmergeMe::checker(int ac, char **av)
{
	for (int i = 1; i < ac; i++)
	{
		if (!isNumber((std::string )av[i]))
		{
			std::cerr << "Error" << std::endl;
			return (false);
		}
	}
	return (true);
}

/* Data Initialization */
void	PmergeMe::initialization(int ac,char **av)
{
	for (int i = 1; i < ac; i++)
	{
		this->stack.push(std::atoi(av[i]));
		this->lst.push_back(std::atoi(av[i]));
	}
	this->elem = lst.size();
}

/* Merge-Insertion Sort Algorithm */
void	PmergeMe::mergeInsertSort()
{
	clock_t start;
	clock_t end;
	
	/* Stack Merge-Insertion Sort Algorithm */
	start = clock();
	 for(int i = 0; i < 1000000; ++i) {
        // do something
    } 
	end = clock();
	this->time_stack = (double)(end - start) / CLOCKS_PER_SEC;
	
	/* List Merge-Insertion Sort Algorithm */
	start = clock();
	for(int i = 0; i < 1000000; ++i) {
        // do something
    } 
	end = clock();
	this->time_list = (double)(end - start) / CLOCKS_PER_SEC;
}

/* Output Results */
void	PmergeMe::print_result()
{
	/* Before */
	std::cout << "Before:\t";
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
	{
		std::list<int>::iterator next_it = it;
        ++next_it;
		if (next_it != lst.end())
			std::cout << *it << " ";
		else
			std::cout << *it << std::endl;
	}
	/* After */
	std::cout << "After:\t";
	std::list<int> ordered_list = lst;
	ordered_list.sort();
	for (std::list<int>::iterator it = ordered_list.begin(); it != ordered_list.end(); ++it)
	{
		std::list<int>::iterator next_it = it;
        ++next_it;
		if (next_it != ordered_list.end())
			std::cout << *it << " ";
		else
			std::cout << *it << std::endl;
	}

	/* Time of Containers */
	std::cout << "Time to process a range of " << elem << " elements with std::stack : " << time_stack << " ??" << std::endl;
	std::cout << "Time to process a range of " << elem << " elements with std::list : " << time_list << " ??" << std::endl;
}