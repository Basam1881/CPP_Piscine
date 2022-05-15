/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:34:27 by bnaji             #+#    #+#             */
/*   Updated: 2022/05/15 23:08:50 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal
{

	public:

		Animal();
		Animal( Animal const & src );
		virtual ~Animal();

		Animal &		operator=( Animal const & rhs );

		std::string const &			getType() const;
		void						setType(std::string type);
		virtual void				makeSound();

	protected:
		std::string		_type;

};

std::ostream &			operator<<( std::ostream & o, Animal const & i );

#endif /* ********************************************************* ANIMAL_H */