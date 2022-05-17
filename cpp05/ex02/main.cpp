/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:28:11 by bnaji             #+#    #+#             */
/*   Updated: 2022/05/17 00:07:46 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
// #include "Bureaucrat.hpp"
// #include "Bureaucrat.hpp"

int main () {
	Bureaucrat				bureaucrat("Ana", 5);
	ShrubberyCreationForm	form("home");
	
	std::cout << bureaucrat << std::endl;
	bureaucrat.signForm(form);
	bureaucrat.incrementGrade();
	std::cout << bureaucrat << std::endl;
	bureaucrat.incrementGrade();
	std::cout << bureaucrat << std::endl;
	bureaucrat.signForm(form);
}
