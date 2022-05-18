/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:28:11 by bnaji             #+#    #+#             */
/*   Updated: 2022/05/18 13:22:07 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"


int main () {
	Bureaucrat				bureaucrat("Ana", 6);
	AForm *					form[4];
	Intern					someRandomIntern;

	std::cout << bureaucrat << std::endl;
	form[0] = someRandomIntern.makeForm("shrubbery creation", "home");
	if (form[0]) {
		bureaucrat.signForm(*form[0]);
		bureaucrat.executeForm(*form[0]);
	}
	form[1] = someRandomIntern.makeForm("robotomy request", "home");
	if (form[1]) {
		bureaucrat.signForm(*form[1]);
		bureaucrat.executeForm(*form[1]);
		bureaucrat.executeForm(*form[1]);
	}
	form[2] = someRandomIntern.makeForm("presidential pardon", "home");
	if (form[2]) {
		bureaucrat.executeForm(*form[2]);
		bureaucrat.signForm(*form[2]);
		bureaucrat.executeForm(*form[2]);
		bureaucrat.incrementGrade();
		bureaucrat.executeForm(*form[2]);
	}
	form[3] = someRandomIntern.makeForm("wrong formName", "home");
	if (form[3]) {
		bureaucrat.signForm(*form[3]);
		bureaucrat.executeForm(*form[3]);
	}
	for (int i = 0; i < 4; i++) {
		delete form[i];
	}
}
