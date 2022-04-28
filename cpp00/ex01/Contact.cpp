/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 02:01:43 by bnaji             #+#    #+#             */
/*   Updated: 2022/04/28 16:12:47 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Contact::Contact()
{
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Contact::~Contact()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/


/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string Contact::getFirstName(void) const {return (this->FirstName); }

std::string Contact::getLastName(void) const {return (this->LastName); }

std::string Contact::getNickName(void) const {return (this->NickName); }

std::string Contact::getPhoneNumber(void) const {return (this->PhoneNumber); }

std::string Contact::getDarkestSecret(void) const {return (this->DarkestSecret); }



void Contact::SetFirstName(std::string str) {this->FirstName = str; }

void Contact::SetLastName(std::string str) {this->LastName = str; }

void Contact::SetNickName(std::string str) {this->NickName = str; }

void Contact::SetPhoneNumber(std::string str) {this->PhoneNumber = str; }

void Contact::SetDarkestSecret(std::string str) {this->DarkestSecret = str; }

/* ************************************************************************** */