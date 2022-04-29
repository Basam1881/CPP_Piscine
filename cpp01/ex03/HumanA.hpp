/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 21:41:34 by bnaji             #+#    #+#             */
/*   Updated: 2022/04/29 23:18:51 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>
# include <string>
# include "Weapon.hpp"

class HumanA
{

	public:

		HumanA(std::string name, Weapon &weapon);
		HumanA( HumanA const & src );
		~HumanA();

		void		attack(void) const;

	private:
		std::string		name;
		Weapon			weapon;
		
};

#endif /* ********************************************************** HUMANA_H */