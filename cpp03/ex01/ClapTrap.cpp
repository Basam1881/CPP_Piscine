/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 10:04:30 by bnaji             #+#    #+#             */
/*   Updated: 2022/05/19 17:42:50 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ClapTrap::ClapTrap() {
	this->_name = "UNKNOWN";
	this->_hitPoints = 10;
	this->_hitPointsMax = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
	std::cout << WHITE << this->_name << " has been created" << RESET << std::endl;
}

ClapTrap::ClapTrap(std::string Name) : _name(Name), _hitPoints(10), _energyPoints(10), _attackDamage(0), _hitPointsMax(10)
{
	std::cout << WHITE << this->_name << " has been created" << RESET << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap & src )
{
	*this = src;
	std::cout << WHITE << this->_name << " Clap has been created as " << src.getName() << RESET << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ClapTrap::~ClapTrap()
{
	std::cout << WHITE << this->_name << " is dieing" << RESET << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ClapTrap &				ClapTrap::operator=( ClapTrap const & rhs )
{
	if ( this != &rhs )
	{
		this->_name = rhs.getName();
		this->_hitPoints = rhs.getHitPoints();
		this->_energyPoints = rhs.getEnergyPoints();
		this->_attackDamage = rhs.getAttackDamage();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, ClapTrap const & i )
{
	o << "[ Name: " << i.getName() << "\t\tHP: " << i.getHitPoints() << "\t\tEP: " << i.getEnergyPoints() << "\t\tAD: " << i.getAttackDamage() << " ]" << std::endl;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void				ClapTrap::attack(const std::string& target) {
	if (this->_energyPoints > 0 && this->_hitPoints > 0) {
		std::cout << YELLOW << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << RESET << std::endl;
		this->_energyPoints--;
	}
	else
		std::cout << YELLOW << this->_name << " has no enough energy points!!" << RESET << std::endl;
}

void				ClapTrap::takeDamage(unsigned int amount) {
	if ((int)this->_hitPoints - (int)amount >= 0) {
		std::cout << RED << "ClapTrap " << this->_name << " loses " << amount << " hit points." << RESET << std::endl;
		this->_hitPoints -= amount;
	}
	else {
		std::cout << RED << "ClapTrap " << this->_name << " loses " << this->_hitPoints << " hit points." << RESET << std::endl;
		this->_hitPoints = 0;
	}
}

void				ClapTrap::beRepaired(unsigned int amount) {
	if (this->_energyPoints > 0 && this->_hitPoints > 0) {
		if (this->_hitPoints + amount <= this->_hitPointsMax) {
			std::cout << BLUE << "ClapTrap " << this->_name << " gets " << amount << " hit points." << RESET << std::endl;	
			this->_hitPoints += amount;
		}
		else {
			std::cout << BLUE << "ClapTrap " << this->_name << " gets " << this->_hitPointsMax - this->_hitPoints << " hit points." << RESET << std::endl;
			this->_hitPoints = this->_hitPointsMax;
		}
		this->_energyPoints--;
	}
	else
		std::cout << BLUE << this->_name << " has no enough energy points!!" << RESET << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string	const &				ClapTrap::getName(void) const { return (this->_name); }

unsigned int	const &			ClapTrap::getHitPoints(void) const { return (this->_hitPoints); }

unsigned int	const &			ClapTrap::getEnergyPoints(void) const { return (this->_energyPoints); }

unsigned int	const &			ClapTrap::getAttackDamage(void) const { return (this->_attackDamage); }


void				ClapTrap::setName(std::string name) { this->_name = name; }

void				ClapTrap::setHitPoints(int hitPoints) { this->_hitPoints = hitPoints; }

void				ClapTrap::setEnergyPoints(int energyPoints) { this->_energyPoints = energyPoints; }

void				ClapTrap::setAttackDamage(int attackDamage) { this->_attackDamage = attackDamage; }


/* ************************************************************************** */