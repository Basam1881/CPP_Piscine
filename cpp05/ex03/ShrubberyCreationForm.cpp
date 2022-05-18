/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 19:50:07 by bnaji             #+#    #+#             */
/*   Updated: 2022/05/18 09:55:35 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", 145, 137), _target("UKNOWN")
{
	std::cout << "Shrubbery Form is created" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "Shrubbery Form is created" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm & src ) : AForm(src)
{
	*this = src;
	std::cout << "Shrubbery Form is copied" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Shrubbery Form is deleted" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ShrubberyCreationForm &				ShrubberyCreationForm::operator=( ShrubberyCreationForm const & rhs )
{
	if ( this != &rhs )
	{
		this->_target = rhs.getTarget();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, ShrubberyCreationForm const & i )
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

int					ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	if (!this->isExecutable(executor))
		return (0);
	std::string fileName =  this->_target + "_shrubbery";
	std::ofstream newfile;
	newfile.open(fileName.c_str());
	if (!newfile)
		return (0);
	newfile << 
"                     . . .\n\
                   .        .  .     ..    .\n\
                .                 .         .  .\n\
                                .\n\
                               .                ..\n\
               .          .            .              .\n\
               .            '.,        .               .\n\
               .              'b      *\n\
                .              '$    #.                ..\n\
               .    .           $:   #:               .\n\
             ..      .  ..      *#  @):        .   . .\n\
                          .     :@,@):   ,.**:'   .\n\
              .      .,         :@@*: ..**'      .   .\n\
                       '#o.    .:(@'.@**'  .\n\
               .  .       'bq,..:,@@*'   ,*      .  .\n\
                          ,p$q8,:@)'  .p*'      .\n\
                   .     '  . '@@Pp@@*'    .  .\n\
                    .  . ..    Y7'.'     .  .\n\
                              :@):.\n\
                             .:@:'.\n\
                           .::(@:."
	<< std::endl;
	newfile.close();
	return (1);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string	const &			ShrubberyCreationForm::getTarget() const { return (this->_target); }

void						ShrubberyCreationForm::setTarget(std::string target) { this->_target = target; }

/* ************************************************************************** */