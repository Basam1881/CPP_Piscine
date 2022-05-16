/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:34:22 by bnaji             #+#    #+#             */
/*   Updated: 2022/05/16 12:50:52 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AAnimal::AAnimal() : _type("UNKNOWN")
{
	std::cout << "UNKOWN animal is created" << std::endl;
}

AAnimal::AAnimal( const AAnimal & src )
{
	this->_type = src.getType();
	std::cout << "UNKNOWN animal is created as " << this->_type << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AAnimal::~AAnimal()
{
	std::cout << "UNKNOWN animal is died" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

AAnimal &				AAnimal::operator=( AAnimal const & rhs )
{
	if ( this != &rhs )
	{
		this->_type = rhs.getType();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, AAnimal const & i )
{
	o << i.getType() << " animal";
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void				AAnimal::makeSound() {
	std::cout << this->_type << " does not exist!!" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string const &			AAnimal::getType() const { return (this->_type); }

void						AAnimal::setType(std::string type) { this->_type = type; }

/* ************************************************************************** */