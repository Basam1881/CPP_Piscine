/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:34:42 by bnaji             #+#    #+#             */
/*   Updated: 2022/05/19 15:49:47 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Dog::Dog()
{
	this->_type = "Dog";
	std::cout << this->_type << " is created" << std::endl;
}

Dog::Dog( const Dog & src ) : Animal(src)
{	
	this->_type = src.getType();
	std::cout << this->_type << " is created as " << this->_type << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Dog::~Dog()
{
	std::cout << this->_type << " is died" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Dog &				Dog::operator=( Dog const & rhs )
{
	if ( this != &rhs )
	{
		this->_type = rhs.getType();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Dog const & i )
{
	o << i.getType();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void				Dog::makeSound() {
	std::cout << this->_type << ": Bark Bark like a Dog" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */