#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack> 

template <typename T>
class MutantStack : public std::stack<T> {
	private:
		
	public:
		
		MutantStack() {};
		MutantStack(const MutantStack &copy) 
		{
			*this = &copy;
		}
		MutantStack &operator=(const MutantStack &copy) 
		{
			if (this != &copy)
			{
				*this = copy;
			}
		}
		
		~MutantStack() {};


		typedef typename MutantStack<T>::stack::container_type::iterator iterator;

		iterator begin() {return (this->c.begin());}
		iterator end() {return (this->c.end());}

};

#endif