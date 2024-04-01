#pragma once

# include <iostream>
# include <sstream>
# include <vector>

class RPN {
	private:
		std::string			_operations;
		std::vector<int>	_num;
		std::vector<char>	_op;
		std::vector<int> numbers;
	public:
		RPN();
		RPN(const std::string &operations);
		~RPN();

		RPN(const RPN &copy);
		RPN &operator=(const RPN &copy);
		
		bool	ReversePolishNotationSyntax();

		void	process();
		void	calculate();

		void	printnum();
		void	printop();
};