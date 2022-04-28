/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 02:01:24 by bnaji             #+#    #+#             */
/*   Updated: 2022/04/28 16:12:31 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include "Contact.hpp"

class PhoneBook
{

	public:

		PhoneBook();
		~PhoneBook();

		std::string		FirstName;
		std::string		LastName;
		std::string		NickName;
		std::string		PhoneNumber;
		std::string		DarkestSecret;
		std::string		index;
		int				ContactId;
		void			addContact(void);
		void			displayContact(void) const;
		void			display_all(void);
		int				loop_flag;

	private:
		int			ContactsNum;
		int			ContactsMax;
		int			ContactsIndex;
		void		store(void);
		void		display_field(int i) const;
		int			string_is_digit(std::string, int flag) const;
		std::string	enter_field(int flag);
		Contact		Contacts[8];

};

#endif /* ******************************************************* PHONEBOOK_H */
