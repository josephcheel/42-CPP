#include "Harl.hpp"
#include <iostream>
Harl::Harl()
{

}

Harl::~Harl()
{

}

void Harl::complain(std::string level)
{
	void (Harl::*PtrComplain[4])() = {
		&Harl::debug,
		&Harl::info, 
		&Harl::warning, 
		&Harl::error
	};

	std::string levels[] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};
	
	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			(this->*PtrComplain[i])();
			break ;
		}
	}
	// int i = -1;

	// while (++i < 4)
	// {
	// 	switch(i)
	// 	{
	// 		case 1: 
	// 			this->debug();
	// 		case 2:
	// 			this->info();
	// 		case 3:
	// 			this->warning();
	// 		case 4: 
	// 			this->error();
	// 	}
	// }
 
}

void Harl::debug( void )
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger." << std::endl;
	std::cout << "I really do!" << std::endl;
}
void Harl::info( void )
{
	std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
	std::cout << "You didn’t put enough bacon in my burger!" << std::endl;
	std::cout << "If you did, I wouldn’t be asking for more!" << std::endl;
}
void Harl::warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I’ve been coming for years whereas you started working here since last month." << std::endl;
}
void Harl::error( void )
{
	std::cout << "This is unacceptable!" << std::endl;
	std::cout << "I want to speak to the manager now." << std::endl;
}