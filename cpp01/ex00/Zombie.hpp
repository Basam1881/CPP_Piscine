/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 17:33:08 by bnaji             #+#    #+#             */
/*   Updated: 2022/04/29 21:14:42 by bnaji            ###   ########.fr       */
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
		Zombie* newZombie(std::string name);
		void randomChump(std::string name);


	private:
		std::string		name;
		void			announce(void);

};

#endif /* ********************************************************** ZOMBIE_H */