/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 19:49:58 by bnaji             #+#    #+#             */
/*   Updated: 2022/05/18 10:39:50 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("UKNOWN")
{
	std::cout << "Robot Form is created" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "Robot Form is created" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm & src ) : AForm(src)
{
	*this = src;
	std::cout << "Robot Form is copied" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Robot Form is deleted" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

RobotomyRequestForm &		RobotomyRequestForm::operator=( RobotomyRequestForm const & rhs )
{
	if ( this != &rhs )
	{
		this->_target = rhs.getTarget();
	}
	return *this;
}

std::ostream &				operator<<( std::ostream & o, RobotomyRequestForm const & i )
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

int							RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	if (!this->isExecutable(executor))
		return (0);
	std::cout << "DaDUM DaDUM DaDUM DaDUM !!!" << std::endl;
	if (rand() % 2)
		std::cout << this->getName() << "has been robotomized successfully" << std::endl;
	else
		std::cout << this->getName() << "has failed successfully!!" << std::endl;
	return (1);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string	const &			RobotomyRequestForm::getTarget() const { return (this->_target); }

void						RobotomyRequestForm::setTarget(std::string target) { this->_target = target; }

/* ************************************************************************** */