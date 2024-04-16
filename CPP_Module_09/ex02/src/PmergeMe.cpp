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
		this->vector.push_back(std::atoi(av[i]));
		this->lst.push_back(std::atoi(av[i]));
	}
	this->elem = lst.size();
}

/* Merge-Insertion Sort Algorithm */
void	PmergeMe::sort()
{
	clock_t start;
	clock_t end;
	
	/* Stack Merge-Insertion Sort Algorithm */
	start = clock();
	// for(int i = 0; i < 1000000; ++i) {
    //     // do something
    // }
	this->mergeInsertSort<std::vector<int> >(this->vector);
	for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); ++it)
		std::cout << *it << "\t";
	std::cout << std::endl;
	end = clock();
	this->time_stack = (double)(end - start) / CLOCKS_PER_SEC;
	
	/* List Merge-Insertion Sort Algorithm */
	start = clock();
	// for(int i = 0; i < 1000000; ++i) {
    //     // do something
    // } 
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
	std::cout << "Time to process a range of " << elem << " elements with std::stack\t: " << time_stack << " ??" << std::endl;
	std::cout << "Time to process a range of " << elem << " elements with std::list\t: " << time_list << " ??" << std::endl;
}

/* Binary_Search */
/* @param begin The beginning of a STL container iterator of ints */
/* @param end The end of a STL container iterator of ints */
/* @param find Number to find */
/* @returns True if there is another number equal to find, otherwise returns false */
/* @note list of numbers should be ordered */
template <typename T>
bool PmergeMe::binary_search(typename T::iterator &begin,typename T::iterator &end, int find)
{
	typename T::iterator left = begin;
	typename T::iterator right = end;

	typename T::iterator it = begin;
	while (left < right)
	{
		typename T::iterator mid = left + (std::distance(left, right)) / 2;
		if (*mid == find)
			return true;
		if (*mid > find)
			right = mid;
		else
			left = mid + 1;
	}
	return false;
}

/* Lower Bound */
/* @param begin The beginning of a STL container iterator of ints */
/* @param end The end of a STL container iterator of ints */
/* @param find Number to find */
/* @returns The lowest or equal number found on the list */
/* @note list of numbers should be ordered */
template <typename T>
typename T::iterator	PmergeMe::lower_bound(typename T::iterator &begin,typename T::iterator &end, int find)
{
	typename T::iterator left = begin;
	typename T::iterator right = end;

	typename T::iterator it = begin;
	while (left < begin)
	{
		typename T::iterator mid = left + (std::distance(left, right)) / 2;
		if (*mid == find)
			return *mid;
		if (*mid > find)
			right = mid;
		else
			left = mid + 1;
	}
	return left;
}

/* */
// template <typename T>
// static void swapme(typename T::iterator &first, typename T::iterator &second)
// {
// 	int tmp = *first;
// 	*first = *second;
// 	*second = tmp;
// }
// template<typename U>
// static void swapme(U &a, U &b) {
//     U temp = a;
//     a = b;
//     b = temp;
// }
template <class Iterator>
void swapval(Iterator a, Iterator b)
{

    int temp = *a;
    *a = *b;
    *b = temp;
}

/*  */
template <typename T>
void	PmergeMe::mergeInsertSort(T &pairs)
{
	// T pairs;
	// for (typename T::iterator it = container.begin(); it != container.end(); ++it)
	// 	pairs.push_back(*it);
	/* Swap Pairs */
	for (int i = 0; i < static_cast<int>(pairs.size()); i++)
	{
		if (i == static_cast<int>(pairs.size()) - 1)
			continue ;
		if (i == 0 || (i != 1 && (i % 2 == 0 && i != static_cast<int>(pairs.size()))))
		{
			typename T::iterator it1 = pairs.begin() + i;
			typename T::iterator it2 = pairs.begin() + i + 1;
			if (*it1 > *it2)
				swapval(it1, it2);
		}
	}
	std::cout << std::endl;
	for (typename T::iterator it = pairs.begin(); it != pairs.end(); ++it)
		std::cout << *it << "\t";
	std::cout << std::endl;
}