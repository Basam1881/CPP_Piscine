/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 02:01:12 by bnaji             #+#    #+#             */
/*   Updated: 2022/04/28 15:48:17 by bnaji            ###   ########.fr       */
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
	this->loop_flag = 1;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PhoneBook::~PhoneBook()
{
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

int	PhoneBook::string_is_digit(std::string str, int flag) const {
	if (!flag && str.find_first_not_of("0123456789") == std::string::npos)
		return (1);
	else if (flag == 1 && str.find_first_not_of("0123456789") == std::string::npos)
		return (1);
	return (0);
}

void	PhoneBook::store(void) {
	this->Contacts[this->ContactsIndex].SetFirstName(this->FirstName);
	this->Contacts[this->ContactsIndex].SetLastName(this->LastName);
	this->Contacts[this->ContactsIndex].SetNickName(this->NickName);
	this->Contacts[this->ContactsIndex].SetPhoneNumber(this->PhoneNumber);
	this->Contacts[this->ContactsIndex].SetDarkestSecret(this->DarkestSecret);
}

void	PhoneBook::display_field(int i) const {
	std::string	tmp;

	std::cout << std::setw(10) << i << "|";
	tmp = (this->Contacts[i].getFirstName()).substr(0, 10);
	if ((this->Contacts[i].getFirstName()).length() > 10)
		tmp = tmp.insert(10, ".");
	std::cout << std::setw(10) << tmp << "|";
	tmp = (this->Contacts[i].getLastName()).substr(0, 10);
	if ((this->Contacts[i].getLastName()).length() > 10)
		tmp = tmp.insert(10, ".");
	std::cout << std::setw(10) << tmp << "|";
	tmp = (this->Contacts[i].getNickName()).substr(0, 10);
	if ((this->Contacts[i].getNickName()).length() > 10)
		tmp = tmp.insert(10, ".");
	std::cout << std::setw(10) << tmp << std::endl;
}

std::string	PhoneBook::enter_field(int flag) {
	std::string	str;
	std::size_t	i;

	while (this->loop_flag) {
		if (flag == 1)
			std::cout << "Enter First Name: ";
		else if (flag == 2)
			std::cout << "Enter Last Name: ";
		else if (flag == 3)
			std::cout << "Enter Nick Name: ";
		else if (flag == 4)
			std::cout << "Enter Phone Number: ";
		else if (flag == 5)
			std::cout << "Enter Darkest Secret: ";
		if (!std::getline(std::cin, str)) {
			std::cout << std::endl;
			this->loop_flag = 0;
			break ;
		}
		i = 0;
		while (true) {
			i = str.find_first_of("\t\v\r\f\n", i);
			if (i != std::string::npos)
				str.erase(i, 1);	
			else
				break ;
		}
		if ((!str.empty() && str.find_first_not_of(" \t\v\r\f\n") != std::string::npos)) {
			if (!(flag == 4 && str[0] && !this->string_is_digit(str, 1)))
				break ;	
		}
	}
	return (str);
}

void	PhoneBook::addContact(void) {
	this->FirstName = enter_field(1);
	this->LastName = enter_field(2);
	this->NickName = enter_field(3);
	this->PhoneNumber = enter_field(4);
	this->DarkestSecret = enter_field(5);
	if (this->ContactsIndex == this->ContactsMax - 1)
		this->ContactsIndex = -1;
	if (this->ContactsNum != this->ContactsMax - 1)
		this->ContactsNum++;
	this->ContactsIndex++;
	this->store();
}

void	PhoneBook::display_all(void) {
	if (this->ContactsNum >= 0) {
		std::cout << "---------- ---------- ---------- ----------" << std::endl;
		std::cout << "|  INDEX  | FIRSTNAME| LASTNAME | NICKNAME |" << std::endl;
		std::cout << "---------- ---------- ---------- ----------" << std::endl;
		for (int i = 0; i <= this->ContactsNum; i++) {
			this->display_field(i);
		}
		std::cout << "---------- ---------- ---------- ----------" << std::endl;
		while (this->loop_flag)
		{
			std::cout << "Enter Contact's ID: ";
			std::getline(std::cin, this->index);
			if (this->index[0] && this->string_is_digit(this->index, 0)) {
				this->ContactId = std::stoi(this->index);
				std::cout << "FirstName: " << this->Contacts[this->ContactId].getFirstName() << std::endl;
				std::cout << "LastName: " << this->Contacts[this->ContactId].getLastName() << std::endl;
				std::cout << "NickName: " << this->Contacts[this->ContactId].getNickName() << std::endl;
				std::cout << "PhoneNumber: " << this->Contacts[this->ContactId].getPhoneNumber() << std::endl;
				std::cout << "Darkest Secret: " << this->Contacts[this->ContactId].getDarkestSecret() << std::endl;
				break ;
			}
			if (!std::getline(std::cin, this->index)) {
				std::cout << std::endl;
				this->loop_flag = 0;
				break ;
			}
		}
	}
	else
		std::cout << "There are no contacts to search for yet!" << std::endl;
}



void	PhoneBook::displayContact(void) const {
	if (this->ContactId >= 0 && this->ContactId < this->ContactsMax) {
		if (this->ContactId <= this->ContactsNum) {
			this->display_field(this->ContactId);
		}
		else
			std::cout << "Contact doesn't exist yet..." << std::endl;
	}
	else {
		std::cout << "index is out of range" << std::endl;
	}
}

/* ************************************************************************** */