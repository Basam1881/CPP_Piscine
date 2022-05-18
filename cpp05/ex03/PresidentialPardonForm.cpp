/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 19:49:50 by bnaji             #+#    #+#             */
/*   Updated: 2022/05/18 10:20:29 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("UKNOWN")
{
	std::cout << "Presidential Form is created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << "Presidential Form is created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm & src ) : AForm(src)
{
	*this = src;
	std::cout << "Presidential Form is copied" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Presidential Form is deleted" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

PresidentialPardonForm &				PresidentialPardonForm::operator=( PresidentialPardonForm const & rhs )
{
	if ( this != &rhs )
	{
		this->_target = rhs.getTarget();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, PresidentialPardonForm const & i )
{
	o << i.getName() << " Form is ";
	if (!i.getIsSigned())
		o << "not ";
	o << "signed [ Required grade to sign: " << i.getSignGrade()
		<< " | Required grade to execute: " << i.getExecGrade()
		<< " | Target: " << i.getTarget() << "]";
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

int							PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	if (!this->isExecutable(executor))
		return (0);
	std::cout << this->getName() << " has been pardoned by Zaphod Beeblebro" << std::endl;
	return (1);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string	const &			PresidentialPardonForm::getTarget() const { return (this->_target); }

void						PresidentialPardonForm::setTarget(std::string target) { this->_target = target; }

/* ************************************************************************** */