/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 14:35:17 by bnaji             #+#    #+#             */
/*   Updated: 2022/05/15 19:47:32 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ScavTrap::ScavTrap() {
	this->_name = "UNKNOWN";
	this->_hitPoints = 100;
	this->_hitPointsMax = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << WHITE << this->_name << " Scav has been created" << RESET << std::endl;
}

ScavTrap::ScavTrap(std::string Name)
{
	this->_name = Name;
	this->_hitPoints = 100;
	this->_hitPointsMax = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << WHITE << this->_name << " Scav has been created" << RESET << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap & src ) : ClapTrap(src)
{
	this->_name = src._name;
	this->_hitPoints = src._hitPoints;
	this->_hitPointsMax = src._hitPointsMax;
	this->_energyPoints = src._energyPoints;
	this->_attackDamage = src._attackDamage;
	std::cout << WHITE << this->_name << " Scav has been created as " << src.getName() << RESET << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ScavTrap::~ScavTrap()
{
	std::cout << WHITE << this->_name << " Scav is dieing" << RESET << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/


/*
** --------------------------------- METHODS ----------------------------------
*/

void				ScavTrap::attack(const std::string& target) {
	if (this->_energyPoints > 0 && this->_hitPoints > 0) {
		std::cout << YELLOW << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << RESET << std::endl;
		this->_energyPoints--;
	}
	else
		std::cout << YELLOW << this->_name << " has no enough energy points!!" << RESET << std::endl;
}

void				ScavTrap::guardGate() {
	std::cout << PURPLE << "UNKOWN Scav is now in Gate keeper mode" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */