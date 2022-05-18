/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 12:23:32 by bnaji             #+#    #+#             */
/*   Updated: 2022/05/18 12:45:04 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{

	public:

		Intern();
		Intern( Intern const & src );
		~Intern();

		Intern &		operator=( Intern const & rhs );

		AForm *			makeForm(std::string formName, std::string target);

	private:
		AForm *		makeShrubberyCreationForm(std::string target);
		AForm *		makeRobotomyRequestForm(std::string target);
		AForm *		makePresidentialPardonForm(std::string target);

};

std::ostream &			operator<<( std::ostream & o, Intern const & i );

typedef AForm *		(Intern::*Forms)(std::string target);

#endif /* ********************************************************** INTERN_H */