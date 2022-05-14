/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 17:28:11 by bnaji             #+#    #+#             */
/*   Updated: 2022/05/12 13:59:23 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
	Zombie	zombie;
	Zombie	*zombies;
	int		n = 5;

	zombies = zombie.zombieHorde(n, "Bnaji");
	for (int i = 0; i < n; i++) {
		zombies[i].announce();
	}
	delete [] zombies;
	return (0);
}
