/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 13:59:59 by bnaji             #+#    #+#             */
/*   Updated: 2022/05/23 11:05:23 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZATION_HPP
# define SERIALIZATION_HPP

# include <iostream>
# include <string>
# include <stdint.h>

class Serialization
{

	public:

		Serialization();
		Serialization( Serialization const & src );
		~Serialization();

		struct Data
		{
			std::string		str;
			int						num;
		};
		
		uintptr_t		serialize(Data* ptr);
		Data *			deserialize(uintptr_t raw);
		
		Data *						getReceiver() const;
		void							setReceiver(Data * receiver);
		uintptr_t					getUIntPtr() const;
		void							setUIntPtr(uintptr_t uIntPtr);

		Serialization &		operator=( Serialization const & rhs );

	private:
		Data *			_receiver;
		uintptr_t		_uIntptr;

};

#endif /* *************************************************** SERIALIZATION_H */