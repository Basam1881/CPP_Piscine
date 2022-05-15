/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 10:00:32 by bnaji             #+#    #+#             */
/*   Updated: 2022/05/15 19:12:41 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
	ScavTrap goblin("Muazzum");

	std::cout << GREEN << goblin << RESET;
	goblin.takeDamage(10);
	std::cout << GREEN << goblin << RESET;
	goblin.beRepaired(5);
	std::cout << GREEN << goblin << RESET;
	goblin.guardGate();
	std::cout << GREEN << goblin << RESET;
	goblin.setAttackDamage(20);
}
