/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 02:01:24 by bnaji             #+#    #+#             */
/*   Updated: 2022/04/25 17:19:53 by bnaji            ###   ########.fr       */
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
		PhoneBook( PhoneBook const & src );
		~PhoneBook();

		std::string		FirstName;
		std::string		LastName;
		std::string		NickName;
		std::string		PhoneNumber;
		std::string		DarkestSecret;
		std::string		index;
		int				ContactId;
		void			addContact(void);
		void			displayContact(void);

		PhoneBook &		operator=( PhoneBook const & rhs );

	private:
		int		ContactsNum;
		int		ContactsMax;
		int		ContactsIndex;
		void	store(void);
		Contact	Contacts[8];

};

std::ostream &			operator<<( std::ostream & o, PhoneBook const & i );

#endif /* ******************************************************* PHONEBOOK_H */