/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 10:04:35 by bnaji             #+#    #+#             */
/*   Updated: 2022/05/15 18:55:34 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# define GREEN "\033[38;5;46m"
# define WHITE "\033[1;37m"
# define BLUE "\033[1;36m"
# define YELLOW "\033[1;33m"
# define RED "\033[1;31m"
# define PURPLE "\033[1;35m"
# define RESET "\033[m"

# include <iostream>
# include <string>

class ClapTrap
{

	public:

		ClapTrap();
		ClapTrap(std::string Name);
		ClapTrap( ClapTrap const & src );
		~ClapTrap();

		ClapTrap &		operator=( ClapTrap const & rhs );

		std::string	const &				getName(void) const;
		unsigned int const &			getHitPoints(void) const;
		unsigned int const &			getEnergyPoints(void) const;
		unsigned int const &			getAttackDamage(void) const;
		
		void				setName(std::string name);
		void				setHitPoints(int hitPoints);
		void				setEnergyPoints(int energyPoints);
		void				setAttackDamage(int attackDamage);
		
		void				attack(const std::string& target);
		void				takeDamage(unsigned int amount);
		void				beRepaired(unsigned int amount);


	private:
		std::string						_name;
		unsigned int					_hitPoints;
		unsigned int					_energyPoints;
		unsigned int					_attackDamage;

};

std::ostream &			operator<<( std::ostream & o, ClapTrap const & i );

#endif /* ******************************************************** CLAPTRAP_H */