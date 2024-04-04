# include "../inc/MutantStack.hpp"
# include <list>

int main()
{
	{
		/* Subject Tests */
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);
		
		std::cout << "Top " << mstack.top() << std::endl;
		
		mstack.pop(); // deletes the first one
		
		std::cout << "Size " << mstack.size() << std::endl;
		
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...] 
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		
		++it;
		--it;
		
		std::cout <<  "Numbers: ";
		while (it != ite)
		{
			std::cout << *it << ' ';
			++it;
		}
		std::cout << std::endl;
		std::stack<int> s(mstack);

		std::cout << "Size " << s.size() << std::endl;
		// return (0);
	}
	{
		/* More Tests */
		
		/* Constructor */
		MutantStack<std::string>	StringTest;
		MutantStack<double>			DoubleTest;

		/* Push Method */
		StringTest.push("String 1");
		StringTest.push("String 2");
		StringTest.push("String 3");
		StringTest.push("String 4");

		DoubleTest.push(12.12);
		DoubleTest.push(22.22);
		DoubleTest.push(32.32);
		DoubleTest.push(42.42);
		
		/* Size Method */
		std::cout << "Size " << StringTest.size() << std::endl;
		
		std::cout << "Size " << DoubleTest.size() << std::endl;
		
		/* Top Method */
		std::cout << "Top \"" << StringTest.top() << "\"" << std::endl;

		std::cout << "Top " << DoubleTest.top() << std::endl;
		
		/* Iterators */
		std::cout << "String Stack Content: "; 
		for (MutantStack<std::string>::iterator it = StringTest.begin(); it != StringTest.end(); ++it)
			std::cout << *it << ", ";

		std::cout << std::endl;
		std::cout << "Double Stack Content: "; 
		for (MutantStack<double>::iterator it = DoubleTest.begin(); it != DoubleTest.end(); ++it)
			std::cout << *it << ", ";
		std::cout << std::endl;
		
		/* Pop Method */
		StringTest.pop();
		StringTest.pop();
		StringTest.pop();

		DoubleTest.pop();
		DoubleTest.pop();
		DoubleTest.pop();

		std::cout << "String Stack Content: "; 
		for (MutantStack<std::string>::iterator it = StringTest.begin(); it != StringTest.end(); ++it)
			std::cout << *it << ", ";

		std::cout << std::endl;
		std::cout << "Double Stack Content: "; 
		for (MutantStack<double>::iterator it = DoubleTest.begin(); it != DoubleTest.end(); ++it)
			std::cout << *it << ", ";
		std::cout << std::endl;

		/* Empty Method */
		std::cout << std::boolalpha << StringTest.empty() << std::endl;
		std::cout << std::boolalpha << DoubleTest.empty() << std::endl;

		StringTest.pop();
		DoubleTest.pop();

		std::cout << std::boolalpha << StringTest.empty() << std::endl;
		std::cout << std::boolalpha << DoubleTest.empty() << std::endl;
		
		/* Comparisons */
		MutantStack<double>	Instance1;
		MutantStack<double>	Instance2;

		std::cout << "-------------Comparisons-------------" << std::endl;
		Instance1.push(12.12);
		Instance1.push(12.12);
		Instance2.push(42.22);
		Instance2.push(2.22);
		
		bool result = Instance1 < Instance2;
		std::cout << std::boolalpha << result << std::endl;
		/* Destructor */
	}
}

// int main()
// {
// 	std::list<int> mstack;

// 	mstack.push_back(5);
// 	mstack.push_back(17);
	
// 	std::cout << mstack.front() << std::endl;
	
// 	mstack.pop_front();
	
// 	std::cout << mstack.size() << std::endl;
	
// 	mstack.push_back(3);
// 	mstack.push_back(5);
// 	mstack.push_back(737);
// 	//[...] 
// 	mstack.push_back(0);
// 	std::list<int>::iterator it = mstack.begin();
// 	std::list<int>::iterator ite = mstack.end();
	
// 	++it;
// 	--it;
	
// 	while (it != ite)
// 	{
// 		std::cout << *it << std::endl;
// 		++it;
// 	}
// 	std::list<int> s(mstack);
// 	return 0;
// }
