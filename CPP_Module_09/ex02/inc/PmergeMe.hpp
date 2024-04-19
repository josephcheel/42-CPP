#pragma once
# include <iostream>
# include <ctime>
# include <vector>
# include <list>
#include <iostream>
#include <deque>
#include <cmath>
#include <algorithm>
#include <iterator>

class PmergeMe {
private:
	/* Containers */
	std::vector<int>		unordered;
	std::vector<int>		vector;
	std::deque<int>		lst;
	
	/* General Information */
	int			elem;
	double		time_stack;
	double		time_list;
public:
	PmergeMe();
	~PmergeMe();

	bool	checker(int ac, char **av);
	void	initialization(int ac,char **av);

	template <typename T>
	void	mergeInsertSort(T &pairs);
	void 	sort();
	void	print_result();

	template <typename X>
	bool	binary_search(typename X::iterator &begin,typename X::iterator &end, int find);

	// template <typename Iterator>
	// Iterator	ft_lower_bound(Iterator &begin,Iterator &end, int find);
};
