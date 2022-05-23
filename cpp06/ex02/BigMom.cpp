/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BigMom.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 19:51:09 by bnaji             #+#    #+#             */
/*   Updated: 2022/05/23 11:23:48 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BigMom.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

BigMom::BigMom() : _baseRef(_basePtr) {
}

BigMom::BigMom( const BigMom & src ) : _baseRef(src.getBaseRef()) {
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

BigMom::~BigMom() {
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

BigMom &				BigMom::operator=( BigMom const & rhs ){
	if ( this != &rhs ){
		this->_basePtr = rhs.getBasePtr();
	}
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void BigMom::identify(Base* p) {
  A * objA = dynamic_cast<A *>(p);
  B * objB = dynamic_cast<B *>(p);
  C * objC = dynamic_cast<C *>(p);
  if (objA)
    std::cout << "Class Ptr: ( A )" << std::endl;
  else if (objB)
    std::cout << "Class Ptr: ( B )" << std::endl;
  else if (objC)
    std::cout << "Class Ptr: ( C )" << std::endl;
}

void BigMom::identify(Base& p) {
  try {
    A & objA = dynamic_cast<A &>(p);
    std::cout << "Class Ref: ( A )" << std::endl;
    (void)objA;
    return ;
  }
  catch (std::exception & bc) {
    (void)bc;
  }
  try {
    B & objB = dynamic_cast<B &>(p);
    std::cout << "Class Ref: ( B )" << std::endl;
    (void)objB;
    return ;
  }
  catch (std::exception & bc) {
    (void)bc;
  }
  try {
    C & objC = dynamic_cast<C &>(p);
    std::cout << "Class Ref: ( C )" << std::endl;
    (void)objC;
    return ;
  }
  catch (std::exception & bc) {
    (void)bc;
  }
}

Base * BigMom::generate(void) {
  int n = rand() % 3;
  switch (n)
  {
    case 0: {
      A * objA = new A;
      Base *base = objA;
      std::cout << "Class Org: ( A )" << std::endl;
      return base;
    }
    case 1: {
      B * objB = new B;
      Base *base = objB;
      std::cout << "Class Org: ( B )" << std::endl;
      return base;
    }
    case 2: {
      C * objC = new C;
      Base *base = objC;
      std::cout << "Class Org: ( C )" << std::endl;
      return base;
    }
  }
  return NULL;
}

bool					BigMom::testNumBases(int n) {
	int max = 50;
	if (n < 0 || n > max) {
		std::cerr << "Error: Input is outside the range for testNumBases(int n) [Range: 0 - "
			<< max << "]" << std::endl;
		return false;
	}
  for (int i = 0; i < n; i++) {
    std::cout << std::endl << "------------------ " << i + 1 << " ------------------" << std::endl;
    if (this->setBasePtr(this->generate())) {
      this->identify(this->getBasePtr());
      this->identify(*this->getBaseRef());
      delete this->getBasePtr();
      std::cout << std::endl;
    } 
  }
	return true;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

Base *&				BigMom::getBaseRef() const {
	return (this->_baseRef);
}

Base *				BigMom::getBasePtr() const {
	return (this->_basePtr);
}

bool					BigMom::setBasePtr(Base * base) {
	if (base) {
		this->_basePtr = base;
		return true;
	}
	return false;
}

/* ************************************************************************** */