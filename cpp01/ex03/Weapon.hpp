/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 21:41:18 by bnaji             #+#    #+#             */
/*   Updated: 2022/04/30 23:26:26 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string>

class Weapon
{

	public:

		Weapon(std::string type);
		~Weapon();

		std::string		getType(void) const;
		void			setType(std::string type);

	private:
		std::string		_type;
};


#endif /* ********************************************************** WEAPON_H */