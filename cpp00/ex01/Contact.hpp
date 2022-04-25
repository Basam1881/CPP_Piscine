/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 02:01:37 by bnaji             #+#    #+#             */
/*   Updated: 2022/04/25 11:19:50 by bnaji            ###   ########.fr       */
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
		Contact( Contact const & src );
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

		Contact &		operator=( Contact const & rhs );

	private:
		std::string		FirstName;
		std::string		LastName;
		std::string		NickName;
		std::string		PhoneNumber;
		std::string		DarkestSecret;

};

std::ostream &			operator<<( std::ostream & o, Contact const & i );

#endif /* ********************************************************* CONTACT_H */