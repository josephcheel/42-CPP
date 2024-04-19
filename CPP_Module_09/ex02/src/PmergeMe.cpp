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
	this->mergeInsertSort<std::vector<int> >(this->vector);
	end = clock();
	this->time_stack = (double)(end - start) / CLOCKS_PER_SEC;
	
	/* List Merge-Insertion Sort Algorithm */
	start = clock();
	this->mergeInsertSort<std::deque<int> >(this->lst);
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
	std::vector<int> ordered_list = vector;
	for (std::vector<int>::iterator it = ordered_list.begin(); it != ordered_list.end(); ++it)
	{
		std::vector<int>::iterator next_it = it;
        ++next_it;
		if (next_it != ordered_list.end())
			std::cout << *it << " ";
		else
			std::cout << *it << std::endl;
	}

	/* Time of Containers */
	std::cout << std::fixed << std::setprecision(12) << "Time to process a range of " << elem << " elements with std::stack\t: " << time_stack << " sec" << std::endl;
	std::cout << std::fixed << std::setprecision(12) <<"Time to process a range of " << elem << " elements with std::deque\t: " << time_list << " sec" << std::endl;
}

template<typename ForwardIterator, typename Distance>
void advanceIterator(ForwardIterator& it, Distance n) {
    while (n > 0) {
        ++it;
        --n;
    }
    while (n < 0) {
        --it;
        ++n;
    }
}

/* Binary_Search */
/* @param begin The beginning of a STL container iterator of ints */
/* @param end The end of a STL container iterator of ints */
/* @param find Number to find */
/* @returns True if there is another number equal to find, otherwise returns false */
/* @note list of numbers should be ordered */
template <typename ForwardIterator, typename T>
bool binary_search(ForwardIterator &begin, ForwardIterator &end, const T& find)
{
	ForwardIterator left = begin;
    ForwardIterator right = end;

    while (left < right)
    {
        ForwardIterator mid = left;
        advanceIterator(mid, std::distance(left, right) / 2);
        
        if (*mid == find)
            return true;
        if (*mid < find)
            left = mid + 1;
        else
            right = mid;
    }
    return false;
}

/* Lower Bound */
/* @param begin The beginning of a STL container iterator of ints */
/* @param end The end of a STL container iterator of ints */
/* @param find Number to find */
/* @returns The lowest or equal number found on the list */
/* @note list of numbers should be ordered */
template<typename ForwardIterator, typename T>
ForwardIterator ft_lower_bound(ForwardIterator begin, ForwardIterator end, const T& find)
{
    ForwardIterator left = begin;
    ForwardIterator right = end;

    while (left < right)
    {
        ForwardIterator mid = left;
        advanceIterator(mid, std::distance(left, right) / 2);
        
        // if (*mid == find)
        //     return mid;
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
		if (i == static_cast<int>(pairs.size()) - 1 && i % 2 == 0)
			continue ;
		if (i == 0 || (i != 1 && (i % 2 == 0 && i != static_cast<int>(pairs.size()))))
		{
			typename T::iterator it1 = pairs.begin() + i;
			typename T::iterator it2 = pairs.begin() + i + 1;
			if (*it1 > *it2)
				swapIterator(it1, it2);
		}
	}

	// std::cout << "Pairs: [" << pairs.size() << "]";
	// for (typename T::iterator it = pairs.begin(); it != pairs.end(); ++it)
	// {
	// 	std::cout << *it << " ";
	// }
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
	// std::cout << tmp.size() << std::endl;
	// for (typename T::iterator it = tmp.begin(); it != tmp.end(); ++it)
	// {
	// 	std::cout << *it << " ";
	// }
	std::cout << std::endl;
	while (!tmp.empty())
	{
	// 	std::cout << "Pairs: [" << pairs.size() << "]";
	// for (typename T::iterator it = pairs.begin(); it != pairs.end(); ++it)
	// {
	// 	std::cout << *it << " ";
	// }	
		typename T::iterator found = pairs.end(); //std::find(pairs.begin(), pairs.end(), tmp.front());
		for (typename T::iterator it = pairs.begin(); it != pairs.end(); ++it)
		{
			// std::cout << *it << " ";
			if (((it - pairs.begin()) == 1 || (it - pairs.begin()) % 2 != 0)  && *it == tmp.front() && *it != -1)
			{
				found = it;
				break;
			}

		}
		if (found != pairs.end())
		{
			main_chain.push_back(*found);
			pend_chain.push_back(*(found - 1));
			pairs[found - pairs.begin()] = -1;
		}
		tmp.erase(tmp.begin());
	}
	if (!pairs.empty())
	{
		std::cout << pairs.back() << std::endl;
		// for (typename T::iterator it = pairs.begin(); it != pairs.end(); ++it)
		// {
			if (pairs.back() != -1)
			{
				pend_chain.push_back(pairs.back());
				// pairs.erase(pairs.e());
			}
		// }
	}

	std::cout << "Main Chain: [" << main_chain.size() << "]";
	for (typename T::iterator it = main_chain.begin(); it != main_chain.end(); ++it)
	{
			std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::cout << "Pend Chain: [" << pend_chain.size() << "]";
	for (typename T::iterator it = pend_chain.begin(); it != pend_chain.end(); ++it)
	{
		std::cout << *it << " ";

	}
	std::cout << std::endl;

	/* Insertion */
	main_chain.insert(main_chain.begin(), *pend_chain.begin());
	pend_chain[0] = -1;
	int s = 0;
	for (int i = 1; i < static_cast<int>(pend_chain.size()); i++)
	{	
		int jac;
		while ((jac = jacobsthal(i) * 2) < s)
			i++;
		int index = jac;
		if (index >= static_cast<int>(pend_chain.size()))
			index = static_cast<int>(pend_chain.size()) - 1;
		while (index > 0 &&  index >= s)
		{
			typename T::iterator lower;
			lower = ft_lower_bound(main_chain.begin(), main_chain.end(), static_cast<int>(pend_chain[index]));
			if  (pend_chain[index] != -1)
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