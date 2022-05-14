#include "Harl.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Harl::Harl(std::string level) : _level(level)
{
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Harl::~Harl()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/


/*
** --------------------------------- METHODS ----------------------------------
*/

void	Harl::_debug() {
	std::cout << BLUE << "[ DEBUG ]" << RESET << std::endl;
	std::cout << WHITE << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << RESET << std::endl;
}

void	Harl::_info() {
	std::cout << GREEN << "[ INFO ]" << RESET << std::endl;
	std::cout << WHITE << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << RESET << std::endl;
}

void	Harl::_warning() {
	std::cout << YELLOW << "[ WARNING ]" << RESET << std::endl;
	std::cout << WHITE << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << RESET << std::endl;
}

void	Harl::_error() {
	std::cout << RED << "[ ERROR ]" << RESET << std::endl;
	std::cout << WHITE << "This is unacceptable! I want to speak to the manager now." << RESET << std::endl;
}

void	Harl::complain(std::string level) {
	if (level.empty())
		return ;
	std::string		levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	complainFuncs _CFuncs[] = 
	{
		&Harl::_debug,
		&Harl::_info,
		&Harl::_warning,
		&Harl::_error,
		NULL
	};
	int		i = -1;
	while (level.compare(levels[++i]));
	switch (i)
	{
		case DEBUG:
			(this->*_CFuncs[0])();
		case INFO:
			(this->*_CFuncs[1])();
		case WARNING:
			(this->*_CFuncs[2])();
		case ERROR:
			(this->*_CFuncs[3])();
		
		default:
			break;
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */