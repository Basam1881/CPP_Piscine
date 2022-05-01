/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 17:25:02 by bnaji             #+#    #+#             */
/*   Updated: 2022/05/01 03:45:34 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>
#include "FileReplacer.hpp"

int	main (int ac, char **av) {
	if (ac != 4) {
		std::cerr << "Invalid Arguments" << '\n';
		return (1);
	}
	FileReplacer file(av[1], av[2], av[3]);
	file.replace();
	if (file.fail())
		std::cout << "Replaced has failed\n";
}
