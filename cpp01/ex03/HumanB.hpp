/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 21:41:25 by bnaji             #+#    #+#             */
/*   Updated: 2022/04/29 22:24:22 by bnaji            ###   ########.fr       */
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
		void		setWeapon(Weapon weapon);

	private:
		std::string		name;
		Weapon			weapon;

};

#endif /* ********************************************************** HUMANB_H */