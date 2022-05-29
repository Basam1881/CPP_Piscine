/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 10:00:32 by bnaji             #+#    #+#             */
/*   Updated: 2022/05/29 19:18:54 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
	ClapTrap darkKnight("Bassam");
	ClapTrap goblin("Muazzum");

	std::cout << PURPLE << darkKnight << RESET;
	std::cout << GREEN << goblin << RESET;
	darkKnight.setAttackDamage(3);
	darkKnight.attack(goblin.getName());
	goblin.takeDamage(darkKnight.getAttackDamage());
	std::cout << GREEN << goblin << RESET;
	goblin.beRepaired(2);
	std::cout << GREEN << goblin << RESET;
	goblin.beRepaired(2);
	std::cout << GREEN << goblin << RESET;
	std::cout << PURPLE << darkKnight << RESET;
	goblin.setAttackDamage(20);
	goblin.attack(darkKnight.getName());
	darkKnight.takeDamage(goblin.getAttackDamage());
	std::cout << PURPLE << darkKnight << RESET;
}
