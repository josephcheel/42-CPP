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
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		
		iterator begin() {return (this->c.begin());}
		iterator end() {return (this->c.end());}
		
		const_iterator begin() const { return (std::stack<T>::c.begin()); }
		const_iterator end() const { return (std::stack<T>::c.end()); }

};

#endif