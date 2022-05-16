/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 20:01:45 by bnaji             #+#    #+#             */
/*   Updated: 2022/05/16 21:08:00 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;
class Form
{

	public:

		Form();
		Form(std::string const name, int const signGrade, int const execGrade);
		Form( Form const & src );
		~Form();

		Form &		operator=( Form const & rhs );

		std::string	const &		getName() const;
		bool const &			getIsSigned() const;
		int	const &				getSignGrade() const;
		int	const &				getExecGrade() const;

		void					beSigned(Bureaucrat const & bureaucrat);


		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *	what() const throw();
		};
		
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *	what() const throw();
		};

	private:
		std::string const		_name;
		bool					_isSigned;
		int const				_signGrade;	
		int const				_execGrade;
		void					_tooHigh();
		void					_tooLow();	

};

std::ostream &			operator<<( std::ostream & o, Form const & i );

#endif /* ************************************************************ FORM_H */