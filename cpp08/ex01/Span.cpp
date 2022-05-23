/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 12:47:29 by bnaji             #+#    #+#             */
/*   Updated: 2022/05/23 02:46:01 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Span::Span() : _size(0) {
}

Span::Span(unsigned int size) : _size(size) {
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
  typename std::vector<int>::const_iterator it;
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
			std::cout << "it: " << *it1 << std::endl;
			this->addNumber(*it1);
			it1++;
		}
		catch (Span::IsFullException & e) {
			break ;
		}
	}	
}

void						Span::addNumber(int num) {
	if (this->_span.size() < this->_size) {
		std::cout << "num: " << num << std::endl;
		this->_span.push_back(num);
	}
	else
		throw Span::IsFullException();
}

unsigned int 		Span::shortestSpan() {
	if (this->_span.size() >= 2) {
		unsigned int		min = 0;
		std::vector<int> span = this->_span;
		std::sort(span.begin(), span.end());
		std::vector<int>::iterator it1 = span.begin();
		std::vector<int>::iterator it2 = it1;
		it2++;
		min = abs(*it2 - *it1);
		while (it2 != span.end()) {
			if (abs(*it2 - *it1) < min)
				min = abs(*it2 - *it1);
			it1++;
			it2++;
		}
 		return (min);
	}
	else
		throw Span::NotEnoughElementsException();
}

unsigned int 		Span::longestSpan() {
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