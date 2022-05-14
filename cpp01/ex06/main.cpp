/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 17:25:02 by bnaji             #+#    #+#             */
/*   Updated: 2022/05/14 18:47:52 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main (int ac, char **av) {
	if (ac != 2) {
		std::cerr << "Invalid Argument\n";
		return (1);
	}
	else {
		if (strcmp(av[1], "DEBUG") && strcmp(av[1], "INFO") && strcmp(av[1], "WARNING") && strcmp(av[1], "ERROR")) {
			std::cout << PURPLE << "[ Probably complaining about insignificant problems ]\n";
			return (0);
		}
	}
	Harl	harl(av[1]);
	harl.complain(av[1]);
}
