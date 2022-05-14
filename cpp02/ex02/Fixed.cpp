/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 19:00:26 by bnaji             #+#    #+#             */
/*   Updated: 2022/05/12 13:07:54 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Fixed::Fixed() : _num(0) {
}

Fixed::Fixed( int const num ) {
	this->_num = num * (1 << this->_fb);
}

Fixed::Fixed( float const num ) {
	this->_num = round(num * (1 << this->_fb));
}

Fixed::Fixed( const Fixed & src ) {
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Fixed::~Fixed() {
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Fixed &				Fixed::operator=( Fixed const & rhs ) {
	if ( this != &rhs )
	{
		this->_num = rhs.getRawBits();
	}
	return *this;
}

int					Fixed::operator>( Fixed const & rhs ) const {
	if (this->_num > rhs.getRawBits())
		return (1);
	return (0);
}

int					Fixed::operator<( Fixed const & rhs ) const {
	if (this->_num < rhs.getRawBits())
		return (1);
	return (0);
}

int					Fixed::operator>=( Fixed const & rhs ) const {
	if (this->_num >= rhs.getRawBits())
		return (1);
	return (0);
}

int					Fixed::operator<=( Fixed const & rhs ) const {
	if (this->_num <= rhs.getRawBits())
		return (1);
	return (0);
}

int					Fixed::operator==( Fixed const & rhs ) const {
	if (this->_num == rhs.getRawBits())
		return (1);
	return (0);
}

int					Fixed::operator!=( Fixed const & rhs ) const {
	if (this->_num != rhs.getRawBits())
		return (1);
	return (0);
}

Fixed				Fixed::operator+( Fixed const & rhs ) const {
	return (Fixed((this->_num / (float)(1 << this->_fb)) + (rhs.getRawBits() / (float)(1 << this->_fb))));
}

Fixed				Fixed::operator-( Fixed const & rhs ) const {
	return (Fixed((this->_num / (float)(1 << this->_fb)) - (rhs.getRawBits() / (float)(1 << this->_fb))));
}

Fixed				Fixed::operator*( Fixed const & rhs ) const {
	return (Fixed((this->_num / (float)(1 << this->_fb)) * (rhs.getRawBits() / (float)(1 << this->_fb))));
}

Fixed				Fixed::operator/( Fixed const & rhs ) const {
	return (Fixed((this->_num / (float)(1 << this->_fb)) / (rhs.getRawBits() / (float)(1 << this->_fb))));
}

Fixed &				Fixed::operator++( void ) {
	this->_num++;
	return *this;
}

Fixed				Fixed::operator++( int ) {
	Fixed tmp(*this);
	this->_num++;
	return tmp;
}

Fixed &				Fixed::operator--( void ) {
	this->_num--;
	return *this;
}

Fixed				Fixed::operator--( int ) {
	this->_num++;
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Fixed const & i ) {
	o << ((float)i.getRawBits() / (float)(1 << i.getFracBits()));
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/


float	Fixed::toFloat( void ) const {
	return (this->_num / (1 << this->_fb));
}

int		Fixed::toInt( void ) const {
	return (this->_num / (1 << this->_fb));
}

Fixed &	Fixed::min(Fixed & a, Fixed & b) {
	if (a.getRawBits() < b.getRawBits())
		return (a);
	else
		return (b);
		
}

Fixed &	Fixed::min(Fixed const & a, Fixed const & b) {
	if (a.getRawBits() < b.getRawBits())
		return ((Fixed &)a);
	else
		return ((Fixed &)b);		
}

Fixed &	Fixed::max(Fixed & a, Fixed & b) {
	if (a.getRawBits() > b.getRawBits())
		return (a);
	else
		return (b);
}

Fixed &	Fixed::max(Fixed const & a, Fixed const & b) {
	if (a.getRawBits() > b.getRawBits())
		return ((Fixed &)a);
	else
		return ((Fixed &)b);
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