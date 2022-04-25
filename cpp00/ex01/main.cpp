/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 02:01:30 by bnaji             #+#    #+#             */
/*   Updated: 2022/04/25 17:27:58 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <string.h>

int	main(void) {
	std::string		tmp;
	PhoneBook		phoneBook;

	while (1) {
		std::cout << "Enter Command: ";
		if (!std::getline(std::cin, tmp)) {
			std::cout << std::endl;
			break ;
		}
		if (!tmp.compare("ADD"))
			phoneBook.addContact();
		else if (!tmp.compare("SEARCH")) {
			std::cout << "Enter Contact's ID: ";
			std::getline(std::cin, phoneBook.index);
			if (phoneBook.index[0] >= '0' && phoneBook.index[0] <= '9') {
				phoneBook.ContactId = std::stoi(phoneBook.index);
				phoneBook.displayContact();
			}
			else
				std::cout << "Invalid Input" << std::endl;
		}
		else if (!tmp.compare("EXIT")) {
			break ;
		}
	}
	return (0);
}
