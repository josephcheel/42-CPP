#pragma once

# include <iostream>
# include <sstream>
# include <cstdlib>
# include <stack>

class RPN {
	private:
		std::string			_operations;
		std::stack<int>		_num;
		std::stack<char>	_op;
		std::stack<int> numbers;
	public:
		RPN();
		RPN(const std::string &operations);
		~RPN();

		RPN(const RPN &copy);
		RPN &operator=(const RPN &copy);
		
		bool	ReversePolishNotationSyntax();

		void	process();
		void	calculate();

};
