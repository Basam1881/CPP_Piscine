/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 20:01:50 by bnaji             #+#    #+#             */
/*   Updated: 2022/05/16 21:09:16 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AForm::AForm() : _name("UNKNOWN"), _isSigned(false), _signGrade(1), _execGrade(1)
{
	std::cout << this->_name << " Form is created" << std::endl;
}

AForm::AForm(std::string const name, int const signGrade, int const execGrade) : _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade)
{
	this->_tooHigh();
	this->_tooLow();
	std::cout << this->_name << " Form is created" << std::endl;
}

AForm::AForm( const AForm & src ) : _name(src.getName()), _isSigned(src.getIsSigned()), _signGrade(src.getSignGrade()), _execGrade(src.getExecGrade())
{
	std::cout << "A copy from " << this->_name << " Form is created" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AForm::~AForm()
{
	std::cout << this->_name << " Form is deleted" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

AForm &				AForm::operator=( AForm const & rhs )
{
	(void)rhs;
	return *this;
}

std::ostream &			operator<<( std::ostream & o, AForm const & i )
{
	o << i.getName() << " Form is ";
	if (!i.getIsSigned())
		o << "not ";
	o << "signed [ Required grade to sign: "
		<< i.getSignGrade() << " | Required frade to execute: "
		<< i.getExecGrade() << " ]";
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void					AForm::beSigned(Bureaucrat const & bureaucrat) {
	try {
		if (bureaucrat.getGrade() > this->_signGrade)
			throw AForm::GradeTooLowException();
		else
			this->_isSigned = true;	
	}
	catch (std::exception & e) {
		std::cerr << RED << e.what() << RESET << std::endl;
	}
}

int					AForm::isExecutable(Bureaucrat const & executor) const {
	try
	{
		if (!this->getIsSigned())
			throw AForm::NotSignedException();			
		else if (executor.getGrade() > this->getExecGrade())
			throw AForm::GradeTooLowException();
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << '\n';
		return (0);
	}
	return (1);
}

const char *			AForm::GradeTooHighException::what() const throw() {
	return ("Form: grade is too high");
}

const char *			AForm::GradeTooLowException::what() const throw() {
	return ("Form: Grade is too low");
}

const char *			AForm::NotSignedException::what() const throw() {
	return ("Form Is NOT SIGNED");
}

void					AForm::_tooHigh() {
	try {
		if (this->_signGrade < 1 || this->_execGrade < 1)
			throw AForm::GradeTooHighException();
	}
	catch (std::exception & e) {
		std::cerr << RED << e.what() << RESET << std::endl;
	} 	
}

void					AForm::_tooLow() {
	try {
		if (this->_signGrade > 150 || this->_execGrade > 150)
			throw AForm::GradeTooLowException();
	}
	catch (std::exception & e) {
		std::cerr << RED << e.what() << RESET << std::endl;
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string	const &		AForm::getName() const { return (this->_name); }

bool const &			AForm::getIsSigned() const { return (this->_isSigned); }

int	const &				AForm::getSignGrade() const { return (this->_signGrade); }

int	const &				AForm::getExecGrade() const { return (this->_execGrade); }

/* ************************************************************************** */