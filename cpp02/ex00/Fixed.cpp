/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 19:00:26 by bnaji             #+#    #+#             */
/*   Updated: 2022/05/12 13:09:25 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Fixed::Fixed() : _num(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed( const Fixed & src )
{
	std::cout << "Copy constructor called\n";
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Fixed &				Fixed::operator=( Fixed const & rhs )
{
	std::cout << "Copy assignment operator called\n";

	if ( this != &rhs )
	{
		this->_num = rhs.getRawBits();
	}
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

int		Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called\n";
	return (this->_num);
}

void	Fixed::setRawBits( int const raw ) {
	std::cout << "setRawBits member function called\n";
	this->_num = raw;
}

const int		Fixed::_fb = 8;

/* ************************************************************************** */