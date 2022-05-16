/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:28:11 by bnaji             #+#    #+#             */
/*   Updated: 2022/05/16 21:12:17 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main () {
	Bureaucrat	bureaucrat("Ana", 5);
	Form		form("visa", 3, 1);
	
	std::cout << bureaucrat << std::endl;
	bureaucrat.signForm(form);
	bureaucrat.incrementGrade();
	std::cout << bureaucrat << std::endl;
	bureaucrat.incrementGrade();
	std::cout << bureaucrat << std::endl;
	bureaucrat.signForm(form);
}
