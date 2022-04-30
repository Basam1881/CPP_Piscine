/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 21:41:25 by bnaji             #+#    #+#             */
/*   Updated: 2022/04/30 23:23:04 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include <string>
# include "Weapon.hpp"

class HumanB
{

	public:

		HumanB(std::string name);
		~HumanB();

		void		attack(void) const;
		void		setWeapon(Weapon &weapon);

	private:
		std::string		_name;
		Weapon 			*_weapon;

};

#endif /* ********************************************************** HUMANB_H */