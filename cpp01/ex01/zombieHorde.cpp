/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 20:10:49 by bnaji             #+#    #+#             */
/*   Updated: 2022/04/29 21:39:28 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* Zombie::zombieHorde( int N, std::string name ) {
	Zombie* zombies = new Zombie[N];
	for (int i = 0; i < N; i++) {
		if (!i)
			zombies[i].name = name;
	}
	return (zombies);
}
