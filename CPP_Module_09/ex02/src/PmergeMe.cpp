# include "../inc/PmergeMe.hpp"
#include <iomanip>
#include <limits>

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
	unordered = vector;
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
	// MERGEME(vector.begin(), vector.end(), vector);
	end = clock();
	this->time_stack = (double)(end - start) / CLOCKS_PER_SEC;
	/* List Merge-Insertion Sort Algorithm */
	start = clock();
	// for(int i = 0; i < 1000000; ++i) {
    //     // do something
    // } 
	this->mergeInsertSort<std::deque<int> >(this->lst);
	// MERGEME(lst.begin(), lst.end(), lst);
	end = clock();
	this->time_list = (double)(end - start) / CLOCKS_PER_SEC;
}

/* Output Results */
void	PmergeMe::print_result()
{
	/* Before */
	std::cout << "Before:\t";
	for (std::vector<int>::iterator it = unordered.begin(); it != unordered.end(); ++it)
	{
		std::vector<int>::iterator next_it = it;
        ++next_it;
		if (next_it != unordered.end())
			std::cout << *it << " ";
		else
			std::cout << *it << std::endl;
	}
	/* After */
	std::cout << "After:\t";
	std::deque<int> ordered_list = lst;
	for (std::deque<int>::iterator it = ordered_list.begin(); it != ordered_list.end(); ++it)
	{
		std::deque<int>::iterator next_it = it;
        ++next_it;
		if (next_it != ordered_list.end())
			std::cout << *it << " ";
		else
			std::cout << *it << std::endl;
	}

	/* Time of Containers */
	std::cout << std::fixed << std::setprecision(12) << "Time to process a range of " << elem << " elements with std::stack\t: " << time_stack << " ??" << std::endl;
	std::cout << std::fixed << std::setprecision(12) <<"Time to process a range of " << elem << " elements with std::deque\t: " << time_list << " ??" << std::endl;
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
// template<typename ForwardIterator, typename T>
// ForwardIterator	ft_lower_bound(ForwardIterator &begin, ForwardIterator &end, T& find)
// {
// 	ForwardIterator left = begin;
// 	ForwardIterator right = end;

// 	ForwardIterator it = begin;
// 	while (left < begin)
// 	{
// 		typename std::iterator_traits<ForwardIterator>::difference_type mid = left + (std::distance(left, right)) / 2;
// 		if (*mid == find)
// 			return *mid;
// 		if (*mid > find)
// 			right = mid;
// 		else
// 			left = mid + 1;
// 	}
// 	return left;
// }

template<typename ForwardIterator, typename T>
ForwardIterator ft_lower_bound(ForwardIterator begin, ForwardIterator end, const T& find)
{
    ForwardIterator left = begin;
    ForwardIterator right = end;

    while (left < right)
    {
        ForwardIterator mid = left;
        std::advance(mid, std::distance(left, right) / 2);
        
        if (*mid == find)
            return mid;
        if (*mid < find)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

template<typename Iterator>
void swapIterator(Iterator& t1, Iterator& t2) {
    int tmp = *t1;
    *t1=*t2;
    *t2=tmp;
}

int jacobsthal(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

/*  */
template <typename T>
void	PmergeMe::mergeInsertSort(T &pairs)
{
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
				swapIterator(it1, it2);
		}
	}
	// std::cout << "PAIRS" << std::endl;
	// for (typename T::iterator it = pairs.begin(); it != pairs.end(); ++it)
	// 	std::cout << *it << "\t";
	// std::cout << std::endl;
	
	/* Sort Pairs by the highest number */
	T main_chain;
	T pend_chain;
	T tmp;
	for (int i = 0; i < static_cast<int>(pairs.size()); i++)
	{
		if (i != 0 && (i % 2 != 0 ))
			tmp.push_back(pairs[i]);
	}
	std::sort(tmp.begin(), tmp.end());

	// std::cout << "TMP" << std::endl;
	// for (typename T::iterator it = tmp.begin(); it != tmp.end(); ++it)
	// 	std::cout << *it << "\t";
	// std::cout << std::endl;

	while (!tmp.empty())
	{
		while (1)
		{
			typename T::iterator found = std::find(pairs.begin(), pairs.end(), tmp.front());
			if ((found - pairs.begin()) != 0 && (found - pairs.begin()) % 2 != 0 && found != pairs.end())
			{
				if (found - 1 >= pairs.begin())
				{
					main_chain.push_back(*found);
					pend_chain.push_back(*(found - 1));
					pairs.erase(found);
					pairs.erase(found - 1);
				}
			}
			else
				break ;
			// std::cout << "FOUND" << *found << std::endl;	
		}
		tmp.erase(tmp.begin());
	}
	if (!pairs.empty())
	{
		pend_chain.push_back(pairs.front());
		pairs.erase(pairs.begin());
	}

	/* Insertion */
	main_chain.insert(main_chain.begin(), *pend_chain.begin());
	pend_chain[0] = -1;
	int s = 0;
	for (int i = 1; i < static_cast<int>(pend_chain.size()); i++)
	{	
		int jac;
		while ((jac = jacobsthal(i) * 2) <= s)
			i++;
		int index = jac;
		if (index >= static_cast<int>(pend_chain.size()))
			index = static_cast<int>(pend_chain.size()) - 1;
		while (index > 0 &&  index >= s)
		{
			// typename T::iterator lower = lower_bound_custom(main_chain.begin(), main_chain.end(), static_cast<int>(pend_chain[index]));
			typename T::iterator lower;
			lower = ft_lower_bound(main_chain.begin(), main_chain.end(), static_cast<int>(pend_chain[index]));
			if (lower != main_chain.end() && pend_chain[index] != -1)
				main_chain.insert(main_chain.begin() + (lower - main_chain.begin()), pend_chain[index]);
			else
				break;
			pend_chain[index] = -1;
			index--;
		}
		if (s == static_cast<int>(pend_chain.size() - 1))
			break ;
		s = index;
	}
	pairs = main_chain;
}