/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:34:42 by bnaji             #+#    #+#             */
/*   Updated: 2022/05/16 11:28:58 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Dog::Dog()
{
	this->_type = "Dog";
	this->_brain = new Brain();
	std::cout << this->_type << " is created" << std::endl;
}

Dog::Dog( const Dog & src ) : Animal(src)
{	
	this->_type = src.getType();
	this->_brain = new Brain();
	for (int i = 0; i < 100; i++) {
		if (src.getBrain()->getIdea(i).empty())
			break ;
		this->_brain->setIdea(src.getBrain()->getIdea(i), i);
	}
	std::cout << this->_type << " is created as " << this->_type << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Dog::~Dog()
{
	delete this->_brain;
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
	std::cout << this->_type << ": Bark Bark on a f***ing jerk" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

Brain const * 			Dog::getBrain() const { return (this->_brain); }

void					Dog::setBrain(Brain * brain) { this->_brain = brain; }

/* ************************************************************************** */