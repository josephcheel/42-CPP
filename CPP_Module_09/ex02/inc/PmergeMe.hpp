
# include <algorithm>
# include <iostream>
# include <ctime>
# include <stack>
# include <list>

class PmergeMe {
	private:
		/* Containers */
		std::stack<int>		stack;
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

		void	mergeInsertSort();
		void	print_result();

};