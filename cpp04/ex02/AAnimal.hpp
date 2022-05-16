/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:34:27 by bnaji             #+#    #+#             */
/*   Updated: 2022/05/16 12:52:44 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>
# include <string>

class AAnimal
{

	public:

		AAnimal();
		AAnimal( AAnimal const & src );
		virtual ~AAnimal();

		AAnimal &		operator=( AAnimal const & rhs );

		std::string const &			getType() const;
		void						setType(std::string type);
		virtual void				makeSound() = 0;

	protected:
		std::string		_type;

};

std::ostream &			operator<<( std::ostream & o, AAnimal const & i );

#endif /* ********************************************************* AANIMAL_H */