/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 02:01:30 by bnaji             #+#    #+#             */
/*   Updated: 2022/04/26 17:39:31 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <string.h>

int	main(void) {
	std::string		tmp;
	PhoneBook		phoneBook;

	while (phoneBook.loop_flag) {
		std::cout << "Enter Command: ";
		if (!std::getline(std::cin, tmp)) {
			std::cout << std::endl;
			break ;
		}
		if (!tmp.compare("ADD"))
			phoneBook.addContact();
		else if (!tmp.compare("SEARCH")) {
			phoneBook.display_all();
		}
		else if (!tmp.compare("EXIT")) {
			break ;
		}
	}
	return (0);
}
