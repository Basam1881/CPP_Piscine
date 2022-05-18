/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 12:23:25 by bnaji             #+#    #+#             */
/*   Updated: 2022/05/18 13:16:00 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Intern::Intern()
{
}

Intern::Intern( const Intern & src )
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Intern::~Intern()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Intern &				Intern::operator=( Intern const & rhs )
{
	(void)rhs;
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Intern const & i )
{
	(void)i;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

AForm *		Intern::makeShrubberyCreationForm(std::string target) {
	ShrubberyCreationForm *form = new ShrubberyCreationForm(target);
	return (form);
}

AForm *		Intern::makeRobotomyRequestForm(std::string target) {
	RobotomyRequestForm *form = new RobotomyRequestForm(target);
	return (form);
}

AForm *		Intern::makePresidentialPardonForm(std::string target) {
	PresidentialPardonForm *form = new PresidentialPardonForm(target);
	return (form);
}


AForm *					Intern::makeForm(std::string formName, std::string target) {
	std::string		formNames[] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon",
	};
	Forms	formMaker[] = {
		&Intern::makeShrubberyCreationForm,
		&Intern::makeRobotomyRequestForm,
		&Intern::makePresidentialPardonForm,
		NULL
	};
	int i = -1;
	while (formMaker[++i]) {
		if (!formName.compare(formNames[i])) {
			return ((this->*formMaker[i])(target));
		}
	}
	std::cerr << RED << "Invalid Form Name" << RESET << std::endl;
	return NULL;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */