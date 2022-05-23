/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 10:00:32 by bnaji             #+#    #+#             */
/*   Updated: 2022/05/19 19:38:33 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
	ScavTrap goblin("Allen");
	FragTrap robot1("Muazzum");
	FragTrap robot2(robot1);
	

	robot2.setName("SAMAD");
	std::cout << GREEN << goblin << RESET;
	std::cout << GREEN << robot1 << RESET;
	robot1.attack(goblin.getName());
	goblin.takeDamage(robot1.getAttackDamage());
	std::cout << GREEN << goblin << RESET;
	robot2.attack(goblin.getName());
	goblin.takeDamage(robot2.getAttackDamage());
	std::cout << GREEN << goblin << RESET;
	robot1.highFivesGuys();
	robot2.highFivesGuys();
	goblin.beRepaired(30);
	std::cout << GREEN << goblin << RESET;
	goblin.guardGate();
	goblin.attack(robot1.getName());
	robot1.takeDamage(goblin.getAttackDamage());
	std::cout << GREEN << robot2 << RESET;
	std::cout << GREEN << robot1 << RESET;
	std::cout << GREEN << goblin << RESET;
}
