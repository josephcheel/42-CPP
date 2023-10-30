#ifndef BUREAUCRAT_TOO_LOW_HPP
# define BUREAUCRAT_TOO_LOW_HPP

# include <iostream>
# include <exception>

class BureaucratGradeTooLowException : public std::exception {
	public:
		virtual const char* what() const noexcept {
			return "";
		}
};

#endif 