/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 21:41:31 by bnaji             #+#    #+#             */
/*   Updated: 2022/05/14 23:43:22 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

HumanB::HumanB(std::string name) : _name(name) , _weapon(NULL)
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

HumanB::~HumanB()
{
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void	HumanB::attack(void) const {
	if (!this->_weapon)
		std::cout << this->_name << " attacks with their bare hands" << std::endl;
	else
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

void		HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}

/* ************************************************************************** */