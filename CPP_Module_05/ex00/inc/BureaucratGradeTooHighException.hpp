#ifndef BUREAUCRAT_TOO_HIGH_HPP
# define BUREAUCRAT_TOO_HIGH_HPP

# include <iostream>
# include <exception>

class BureaucratGradeTooHighException : public std::exception {
	public:
		virtual const char* what() const noexcept {
			return "";
		}
};

#endif 