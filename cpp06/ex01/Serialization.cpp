/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 13:59:54 by bnaji             #+#    #+#             */
/*   Updated: 2022/05/20 15:07:28 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Serialization::Serialization() : _receiver(NULL), _uIntptr(0)
{
}

Serialization::Serialization( const Serialization & src )
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Serialization::~Serialization()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Serialization &		Serialization::operator=( Serialization const & rhs )
{
	if ( this != &rhs )
	{
		this->_receiver = rhs.getReceiver();
		this->_uIntptr = rhs.getUIntPtr();
	}
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

uintptr_t		Serialization::serialize(Serialization::Data* ptr) {
	if (!ptr)
		return 0;
	return (reinterpret_cast<uintptr_t>(ptr));
}

Serialization::Data*		Serialization::deserialize(uintptr_t raw) {
	if (!raw)
		return NULL;
	return (reinterpret_cast<Serialization::Data *>(raw));
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

Serialization::Data *		Serialization::getReceiver() const {
	return this->_receiver;
}

void							Serialization::setReceiver(Data * receiver) {
	this->_receiver = receiver;
}

uintptr_t		Serialization::getUIntPtr() const {
	return this->_uIntptr;
}

void							Serialization::setUIntPtr(uintptr_t uIntPtr) {
	this->_uIntptr = uIntPtr;
}

/* ************************************************************************** */