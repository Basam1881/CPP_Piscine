/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:34:22 by bnaji             #+#    #+#             */
/*   Updated: 2022/05/15 23:18:18 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Animal::Animal() : _type("UNKNOWN")
{
	std::cout << "UNKOWN animal is created" << std::endl;
}

Animal::Animal( const Animal & src )
{
	this->_type = src.getType();
	std::cout << "UNKNOWN animal is created as " << this->_type << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Animal::~Animal()
{
	std::cout << "UNKNOWN animal is died" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Animal &				Animal::operator=( Animal const & rhs )
{
	if ( this != &rhs )
	{
		this->_type = rhs.getType();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Animal const & i )
{
	o << i.getType() << " animal";
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void				Animal::makeSound() {
	std::cout << this->_type << " does not exist!!" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string const &			Animal::getType() const { return (this->_type); }

void						Animal::setType(std::string type) { this->_type = type; }

/* ************************************************************************** */