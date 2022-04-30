/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 21:41:34 by bnaji             #+#    #+#             */
/*   Updated: 2022/04/30 23:25:07 by bnaji            ###   ########.fr       */
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
		~HumanA();

		void		attack(void) const;

	private:
		std::string		_name;
		Weapon			&_weapon;
		
};

#endif /* ********************************************************** HUMANA_H */