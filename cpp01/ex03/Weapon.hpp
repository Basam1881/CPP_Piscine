/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 21:41:18 by bnaji             #+#    #+#             */
/*   Updated: 2022/04/29 23:17:01 by bnaji            ###   ########.fr       */
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
		Weapon( Weapon const & src );
		~Weapon();

		std::string		getType(void) const;
		void			setType(std::string type);

	private:
		std::string		type;
};


#endif /* ********************************************************** WEAPON_H */