/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 20:01:50 by bnaji             #+#    #+#             */
/*   Updated: 2022/05/23 07:20:54 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Form::Form() : _name("UNKNOWN"), _isSigned(false), _signGrade(1), _execGrade(1)
{
	std::cout << this->_name << " Form is created" << std::endl;
}

Form::Form(std::string const name, int const signGrade, int const execGrade) : _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade)
{
	this->_tooHigh();
	this->_tooLow();
	std::cout << this->_name << " Form is created" << std::endl;
}

Form::Form( const Form & src ) : _name(src.getName()), _signGrade(src.getSignGrade()), _execGrade(src.getExecGrade())
{
	*this = src;
	std::cout << "A copy from " << this->_name << " Form is created" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Form::~Form()
{
	std::cout << this->_name << " Form is deleted" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Form &				Form::operator=( Form const & rhs )
{
	if (this != &rhs)
	{
		this->_isSigned = rhs.getIsSigned();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Form const & i )
{
	o << i.getName() << " Form is ";
	if (!i.getIsSigned())
		o << "not ";
	o << "signed [ Required srade to sign: " << i.getSignGrade() << " | Required Grade to execute: " << i.getExecGrade() << " ]";
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void					Form::beSigned(Bureaucrat const & bureaucrat) {
	try {
		if (bureaucrat.getGrade() > this->_signGrade)
			throw Form::GradeTooLowException();
		else
			this->_isSigned = true;	
	}
	catch (std::exception & e) {
		std::cerr << RED << e.what() << RESET << std::endl;
	}
}

const char *			Form::GradeTooHighException::what() const throw() {
	return ("Form: grade is too high");
}

const char *			Form::GradeTooLowException::what() const throw() {
	return ("Form: Grade is too low");
}

void					Form::_tooHigh() {
	try {
		if (this->_signGrade < 1 || this->_execGrade < 1)
			throw Form::GradeTooHighException();
	}
	catch (std::exception & e) {
		std::cerr << RED << e.what() << RESET << std::endl;
	} 	
}

void					Form::_tooLow() {
	try {
		if (this->_signGrade > 150 || this->_execGrade > 150)
			throw Form::GradeTooLowException();
	}
	catch (std::exception & e) {
		std::cerr << RED << e.what() << RESET << std::endl;
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string	const &		Form::getName() const { return (this->_name); }

bool const &			Form::getIsSigned() const { return (this->_isSigned); }

int	const &				Form::getSignGrade() const { return (this->_signGrade); }

int	const &				Form::getExecGrade() const { return (this->_execGrade); }

/* ************************************************************************** */