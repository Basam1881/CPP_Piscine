/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:14:27 by bnaji             #+#    #+#             */
/*   Updated: 2022/05/16 19:24:15 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# define GREEN "\033[38;5;46m"
# define WHITE "\033[1;37m"
# define BLUE "\033[1;36m"
# define YELLOW "\033[1;33m"
# define RED "\033[1;31m"
# define PURPLE "\033[1;35m"
# define RESET "\033[m"

# include <iostream>
# include <string>

class Bureaucrat
{

	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat( Bureaucrat const & src );
		~Bureaucrat();

		Bureaucrat &		operator=( Bureaucrat const & rhs );

		std::string	const &		getName() const;
		int	const &				getGrade() const;
		void					incrementGrade();
		void					decrementGrade();

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
		const std::string		_name;
		int						_grade;
		void					_toohigh();
		void					_toolow();

};

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i );

#endif /* ****************************************************** BUREAUCRAT_H */