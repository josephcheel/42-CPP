#pragma once
# include <iostream>
# include <algorithm>
# include <iomanip>
# include <vector>
# include <deque>

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
};
