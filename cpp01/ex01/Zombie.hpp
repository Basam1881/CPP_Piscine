/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 17:33:08 by bnaji             #+#    #+#             */
/*   Updated: 2022/04/29 21:19:08 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{

	public:

		Zombie();
		Zombie( Zombie const & src );
		~Zombie();
		Zombie* 		zombieHorde( int N, std::string name );
		void			announce(void);

	private:
		std::string		name;

};

#endif /* ********************************************************** ZOMBIE_H */