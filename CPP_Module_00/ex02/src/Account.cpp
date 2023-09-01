#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <sstream>
#include <iomanip>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;


Account::Account( int initial_deposit ) : _amount(initial_deposit)
{
	//Update Local object data
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	
	//Update Global object data
	_nbAccounts += 1;
	_accountIndex = _nbAccounts - 1;
	_totalAmount += initial_deposit;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";created" << std::endl;
	return ;	
}

Account::~Account( void )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";closed" << std::endl;
	return ;
}

void	Account::_displayTimestamp( void )
{
	char formattedTime[16]; 
 	std::time_t currentTime = std::time(nullptr);
    std::tm* localTime = std::localtime(&currentTime);

    std::strftime(formattedTime, sizeof(formattedTime), "%Y%m%d_%H%M%S", localTime);
	std::cout << "[" << formattedTime << "] ";

// 	std::time_t current_time;

// 	std::time(&current_time);
// 	std::cout << "[" << current_time << "] ";
}

int	Account::getNbAccounts( void )
{
	return(_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}
int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}
int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}
void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts();
	std::cout << ";total:" << getTotalAmount();
	std::cout << ";deposits:" << getNbDeposits();
	std::cout << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	//Update Local object data
	_amount += deposit;
	_nbDeposits += 1;

	//Update Global object data
	_totalAmount += deposit;
	_totalNbDeposits += 1;
	
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";p_amount:" << _amount - deposit;
	std::cout << ";deposit:" << deposit;
	std::cout << ";amount:" << _amount;
	std::cout << ";nb_deposits:" << _nbDeposits << std::endl;
}
bool	Account::makeWithdrawal( int withdrawal )
{
	
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";p_amount:" << _amount;
	if (withdrawal <= _amount)
	{
		//Update Local object data
		_amount -= withdrawal;
		_nbWithdrawals += 1;
		
		//Update Global object data
		_totalAmount -= withdrawal;
		_totalNbWithdrawals += 1;
		
		std::cout << ";withdrawal:" << withdrawal;
		std::cout << ";amount:" << _amount;
		std::cout << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
		return (true);
	}
	else
	{
		std::cout << ";withdrawal:" << "refused" << std::endl;
		return (false);
	}
}
int		Account::checkAmount( void ) const
{
	return (_amount); 
}
void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";deposits:" << _nbDeposits;
	std::cout << ";withdrawals:" << _nbWithdrawals << std::endl;
}