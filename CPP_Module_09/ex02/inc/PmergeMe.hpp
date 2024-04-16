
# include <algorithm>
# include <iostream>
# include <ctime>
# include <vector>
# include <list>

class PmergeMe {
private:
	/* Containers */
	std::vector<int>		vector;
	std::list<int>		lst;
	
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
	
	template <typename X>
	typename X::iterator	lower_bound(typename X::iterator &begin,typename X::iterator &end, int find);

};
