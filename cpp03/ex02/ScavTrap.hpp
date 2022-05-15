/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 14:35:23 by bnaji             #+#    #+#             */
/*   Updated: 2022/05/15 19:17:23 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{

	public:
		ScavTrap();
		ScavTrap(std::string Name);
		ScavTrap( ScavTrap const & src );
		~ScavTrap();
		
		void				attack(const std::string& target);
		void 				guardGate();

};

#endif /* ******************************************************** SCAVTRAP_H */