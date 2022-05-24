/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 12:47:29 by bnaji             #+#    #+#             */
/*   Updated: 2022/05/24 17:42:40 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Span::Span() : _size(0) {
}

Span::Span(unsigned int size) : _size(size){
}

Span::Span( const Span & src ) {
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Span::~Span()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Span &				Span::operator=( Span const & rhs )
{
	if ( this != &rhs )
	{
		this->_size = rhs.getSize();
		this->_span = rhs.getSpan();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Span const & i )
{
	o << "[ ";
  std::vector<int>::const_iterator it;
  for (it = i.getSpan().begin(); it != i.getSpan().end(); it++) {
    o << *(it);
    it++;
    if (it != i.getSpan().end())
      o << ", ";
    it--;
  }
  o << " ]";
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void						Span::fillSpan(std::vector<int>::const_iterator it1, std::vector<int>::const_iterator it2) {
	while (it1 != it2) {
		try {
			this->addNumber(*it1);
			it1++;
		}
		catch (Span::IsFullException & e) {
			break ;
		}
	}	
}

void						Span::addNumber(int num) {
	try {
		if (this->_span.size() < this->_size)
			this->_span.push_back(num);
		else
			throw Span::IsFullException();
	} catch (IsFullException& e) {
		std::cout << e.what() << std::endl;
	}
}

unsigned int 		Span::shortestSpan() {
	try {
		if (this->_span.size() >= 2) {
			unsigned int		min = 0;
			std::vector<int> span = this->_span;
			std::sort(span.begin(), span.end());
			std::vector<int>::iterator it = span.begin();
			std::vector<int>::iterator it1 = it++;
			std::vector<int>::iterator it2;
			
			min = abs(*it - *it1);
			for (it2 = it; it2 != span.end(); it1++, it2++) 
				if (static_cast<unsigned int>(abs(*it2 - *it1)) < min)
					min = abs(*it2 - *it1);
			return (min);
		}
		else
			throw Span::NotEnoughElementsException();
	} catch (NotEnoughElementsException &e) {
		std::cout << e.what() << std::endl;
		return (0);
	}
}

unsigned int 		Span::longestSpan() {
	try {
		if (this->_span.size() >= 2) {
			std::vector<int> span = this->_span;
			std::sort(span.begin(), span.end());
			std::vector<int>::iterator it1 = span.begin();
			std::vector<int>::iterator it2 = span.end();
			it2--;
			return (abs(*it2 - *it1));
		}
		else
		throw Span::NotEnoughElementsException();
	} catch (NotEnoughElementsException &e) {
		std::cout << e.what() << std::endl;
		return (0);
	}
	
}

const char *	Span::IsFullException::what() const throw() {
	return ("Error: Max number of elements in Span has reached");
}

const char *	Span::NotEnoughElementsException::what() const throw() {
	return ("Error: There isn't enough elements in the Span (you should have 2 or more elements to run this operation)");
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

unsigned int const &			Span::getSize() const {
	return (this->_size);
}

std::vector<int> const &	Span::getSpan() const {
	return (this->_span);
}

std::vector<int>::const_iterator	Span::getBegin() const {
	return (this->_span.begin());
}

std::vector<int>::const_iterator	Span::getEnd() const {
	return (this->_span.end());
}

/* ************************************************************************** */