/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:28:11 by bnaji             #+#    #+#             */
/*   Updated: 2022/05/16 19:45:02 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main () {
	Bureaucrat bureaucrat;
	bureaucrat = Bureaucrat("Muazzum", 0);
	Bureaucrat bureaucrat1("Ana", 160);
	Bureaucrat bureaucrat2(bureaucrat1);
	
	std::cout << bureaucrat << std::endl;
	std::cout << bureaucrat1 << std::endl;
	std::cout << bureaucrat2 << std::endl;
	bureaucrat.incrementGrade();
	bureaucrat1.incrementGrade();
	bureaucrat2.incrementGrade();
	std::cout << bureaucrat << std::endl;
	std::cout << bureaucrat1 << std::endl;
	std::cout << bureaucrat2 << std::endl;
	bureaucrat.decrementGrade();
	bureaucrat1.decrementGrade();
	bureaucrat2.decrementGrade();
	std::cout << bureaucrat << std::endl;
	std::cout << bureaucrat1 << std::endl;
	std::cout << bureaucrat2 << std::endl;
	bureaucrat.decrementGrade();
	bureaucrat1.decrementGrade();
	bureaucrat2.decrementGrade();
	std::cout << bureaucrat << std::endl;
	std::cout << bureaucrat1 << std::endl;
	std::cout << bureaucrat2 << std::endl;
}
