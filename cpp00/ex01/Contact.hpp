/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 02:01:37 by bnaji             #+#    #+#             */
/*   Updated: 2022/04/26 12:44:51 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

class Contact
{

	public:
		Contact();
		~Contact();
		std::string getFirstName(void) const;
		std::string getLastName(void) const;
		std::string getNickName(void) const;
		std::string getPhoneNumber(void) const;
		std::string getDarkestSecret(void) const;
		void SetFirstName(std::string str);
		void SetLastName(std::string str);
		void SetNickName(std::string str);
		void SetPhoneNumber(std::string str);
		void SetDarkestSecret(std::string str);

	private:
		std::string		FirstName;
		std::string		LastName;
		std::string		NickName;
		std::string		PhoneNumber;
		std::string		DarkestSecret;

};

#endif /* ********************************************************* CONTACT_H */