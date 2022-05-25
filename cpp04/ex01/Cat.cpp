/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:34:31 by bnaji             #+#    #+#             */
/*   Updated: 2022/05/25 00:58:40 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cat::Cat()
{
	this->_type = "Cat";
	this->_brain = new Brain();
	std::cout << this->_type << " is created" << std::endl;
}

Cat::Cat( const Cat & src ) : Animal(src)
{
	*this = src;
	std::cout << this->_type << " is created as " << this->_type << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cat::~Cat()
{
	delete this->_brain;
	std::cout << this->_type << " is died" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Cat &				Cat::operator=( Cat const & rhs )
{
	if ( this != &rhs )
	{
		this->_type = rhs.getType();
		this->_brain = new Brain();
		for (int i = 0; i < 100; i++) {
			if (rhs.getBrain()->getIdea(i).empty())
				break ;
			this->_brain->setIdea(rhs.getBrain()->getIdea(i), i);
		}
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Cat const & i )
{
	o << i.getType();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void				Cat::makeSound() {
	std::cout << this->_type << ": Meewwww like a Cat" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

Brain const * 			Cat::getBrain() const { return (this->_brain); }

void					Cat::setBrain(Brain * brain) { this->_brain = brain; }

/* ************************************************************************** */