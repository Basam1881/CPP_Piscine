/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 02:01:12 by bnaji             #+#    #+#             */
/*   Updated: 2022/04/25 17:30:02 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iomanip>
#include <iostream>
#include <string.h>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PhoneBook::PhoneBook()
{
	this->ContactsNum = -1;
	this->ContactsIndex = -1;
	this->ContactsMax = 8;
}

// PhoneBook::PhoneBook( const PhoneBook & src )
// {
// }


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PhoneBook::~PhoneBook()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

// PhoneBook &				PhoneBook::operator=( PhoneBook const & rhs )
// {
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
// 	return *this;
// }

// std::ostream &			operator<<( std::ostream & o, PhoneBook const & i )
// {
	//o << "Value = " << i.getValue();
// 	return o;
// }


/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

void	PhoneBook::store(void) {
	this->Contacts[this->ContactsIndex].SetFirstName(this->FirstName);
	this->Contacts[this->ContactsIndex].SetLastName(this->LastName);
	this->Contacts[this->ContactsIndex].SetNickName(this->NickName);
	this->Contacts[this->ContactsIndex].SetPhoneNumber(this->PhoneNumber);
	this->Contacts[this->ContactsIndex].SetDarkestSecret(this->DarkestSecret);
}

void	PhoneBook::addContact(void) {
	std::cout << "Enter First Name: ";
	std::getline(std::cin, this->FirstName);
	std::cout << "Enter Last Name: ";
	std::getline(std::cin, this->LastName);
	std::cout << "Enter Nick Name: ";
	std::getline(std::cin, this->NickName);
	std::cout << "Enter Phone Number: ";
	std::getline(std::cin, this->PhoneNumber);
	std::cout << "Enter Darkest Secret: ";
	std::getline(std::cin, this->DarkestSecret);
	if (!this->FirstName.empty() && !this->LastName.empty() && !this->NickName.empty() && !this->PhoneNumber.empty() && !this->DarkestSecret.empty()) {
		if (this->ContactsIndex == this->ContactsMax - 1)
			this->ContactsIndex = -1;
		if (this->ContactsNum != this->ContactsMax - 1)
			this->ContactsNum++;
		this->ContactsIndex++;
		this->store();
	}
	else
		std::cout << "Contacts' fields should not be empty" << std::endl;
}

void	PhoneBook::displayContact(void) {
	std::string	tmp;

	if (this->ContactId >= 0 && this->ContactId < this->ContactsMax) {
		if (this->ContactId <= this->ContactsNum) {
			std::cout << std::setw(10) << this->ContactId << "|";
			tmp = (this->Contacts[this->ContactId].getFirstName()).substr(0, 10);
			if ((this->Contacts[this->ContactId].getFirstName()).length() > 10)
				tmp = tmp.insert(10, ".");
			std::cout << std::setw(10) << tmp << "|";
			tmp = (this->Contacts[this->ContactId].getLastName()).substr(0, 10);
			if ((this->Contacts[this->ContactId].getLastName()).length() > 10)
				tmp = tmp.insert(10, ".");
			std::cout << std::setw(10) << tmp << "|";
			tmp = (this->Contacts[this->ContactId].getNickName()).substr(0, 10);
			if ((this->Contacts[this->ContactId].getNickName()).length() > 10)
				tmp = tmp.insert(10, ".");
			std::cout << std::setw(10) << tmp << std::endl;
		}
		else
			std::cout << "Contact doesn't exist yet..." << std::endl;
	}
	else {
		std::cout << "index is out of range" << std::endl;
	}
}



/* ************************************************************************** */