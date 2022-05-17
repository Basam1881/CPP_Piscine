/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 19:00:26 by bnaji             #+#    #+#             */
/*   Updated: 2022/05/17 22:06:02 by bnaji            ###   ########.fr       */
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

Fixed::Fixed( int const num ) {
	std::cout << "Int constructor called\n";
	this->_num = num * (1 << this->_fb);
}

Fixed::Fixed( float const num ) {
	std::cout << "Float constructor called\n";
	this->_num = roundf(num * (1 << this->_fb));
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

std::ostream &			operator<<( std::ostream & o, Fixed const & i )
{
	o << ((float)i.getRawBits() / (float)(1 << i.getFracBits()));
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/


float	Fixed::toFloat( void ) const {
	return ((float)this->_num / (float)(1 << this->_fb));
}

int		Fixed::toInt( void ) const {
	return (this->_num / (1 << this->_fb));
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

int		Fixed::getRawBits(void) const {
	return (this->_num);
}

int		Fixed::getFracBits(void) const {
	return (this->_fb);
}

void	Fixed::setRawBits( int const raw ) {
	this->_num = raw;
}

const int		Fixed::_fb = 8;

/* ************************************************************************** */