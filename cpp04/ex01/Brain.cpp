#include "Brain.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Brain::Brain()
{
	std::cout << "Brain is created" << std::endl;
}

Brain::Brain( const Brain & src )
{
	for (int i = 0; i < 100; i++) {
		this->_ideas[i] = src.getIdea(i);
	}
	std::cout << "Brain is created" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Brain::~Brain()
{
	std::cout << "Brain is destroyed" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Brain &				Brain::operator=( Brain const & rhs )
{
	if ( this != &rhs )
	{
		for (int i = 0; i < 100; i++) {
			this->_ideas[i] = rhs.getIdea(i);
		}
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Brain const & i )
{
	for (int n = 0; n < 100; n++) {
		if (i.getIdea(n).empty())
			break ;
		o << " | " << i.getIdea(n) << " | ";
	}
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string const &		Brain::getIdea(unsigned int n) const { return (this->_ideas[n]); }

void					Brain::setIdea(std::string idea, unsigned int n) { this->_ideas[n] = idea; }

/* ************************************************************************** */