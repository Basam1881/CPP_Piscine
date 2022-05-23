/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 10:00:32 by bnaji             #+#    #+#             */
/*   Updated: 2022/05/19 14:18:23 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
	ScavTrap goblin("Muazzum");
	ClapTrap darkKnight("Bassam");

	std::cout << PURPLE << darkKnight << RESET;
	std::cout << GREEN << goblin << RESET;
	darkKnight.setAttackDamage(3);
	darkKnight.attack(goblin.getName());
	goblin.takeDamage(darkKnight.getAttackDamage());
	std::cout << GREEN << goblin << RESET;
	goblin.beRepaired(2);
	std::cout << GREEN << goblin << RESET;
	goblin.takeDamage(10);
	std::cout << GREEN << goblin << RESET;
	goblin.beRepaired(5);
	std::cout << GREEN << goblin << RESET;
	goblin.guardGate();
	std::cout << GREEN << goblin << RESET;
	goblin.setAttackDamage(20);
}
