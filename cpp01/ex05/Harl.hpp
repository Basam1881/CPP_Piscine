#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>

class Harl
{

	public:

		Harl();
		Harl( Harl const & src );
		~Harl();

		Harl &		operator=( Harl const & rhs );

	private:

};

std::ostream &			operator<<( std::ostream & o, Harl const & i );

#endif /* ************************************************************ HARL_H */