/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 19:18:47 by bnaji             #+#    #+#             */
/*   Updated: 2022/05/15 20:39:25 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

FragTrap::FragTrap() {
	this->_name = "UNKNOWN";
	this->_hitPoints = 100;
	this->_hitPointsMax = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << WHITE << this->_name << " Frag has been created" << RESET << std::endl;
}

FragTrap::FragTrap(std::string Name)
{
	this->_name = Name;
	this->_hitPoints = 100;
	this->_hitPointsMax = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << WHITE << this->_name << " Frag has been created" << RESET << std::endl;
}

FragTrap::FragTrap( const FragTrap & src ) : ClapTrap(src)
{
	this->_name = src._name;
	this->_hitPoints = src._hitPoints;
	this->_hitPointsMax = src._hitPointsMax;
	this->_energyPoints = src._energyPoints;
	this->_attackDamage = src._attackDamage;
	std::cout << WHITE << this->_name << " Frag has been created as " << src.getName() << RESET << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

FragTrap::~FragTrap()
{
	std::cout << WHITE << this->_name << " Frag is dieing" << RESET << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/


/*
** --------------------------------- METHODS ----------------------------------
*/

void			FragTrap::highFivesGuys() {
	std::cout << PURPLE << this->_name << ": Give me a high five guys." << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */