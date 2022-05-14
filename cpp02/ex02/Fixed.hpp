/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 19:00:35 by bnaji             #+#    #+#             */
/*   Updated: 2022/05/12 13:07:03 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{

	public:

		Fixed();
		Fixed( int const num );
		Fixed( float const num );
		Fixed( Fixed const & src );
		~Fixed();

		int				getFracBits(void) const;
		int				getRawBits( void ) const;
		void			setRawBits( int const raw );
		float			toFloat( void ) const;
		int				toInt( void ) const;
		static Fixed &	min(Fixed & a, Fixed & b);
		static Fixed &	min(Fixed const & a, Fixed const & b);
		static Fixed &	max(Fixed & a, Fixed & b);
		static Fixed &	max(Fixed const & a, Fixed const & b);

		Fixed &			operator=( Fixed const & rhs );
		int				operator>( Fixed const & rhs ) const;
		int				operator<( Fixed const & rhs ) const;
		int				operator>=( Fixed const & rhs ) const;
		int				operator<=( Fixed const & rhs ) const;
		int				operator==( Fixed const & rhs ) const;
		int				operator!=( Fixed const & rhs ) const;
		Fixed			operator+( Fixed const & rhs ) const;
		Fixed			operator-( Fixed const & rhs ) const;
		Fixed			operator*( Fixed const & rhs ) const;
		Fixed			operator/( Fixed const & rhs ) const;
		Fixed &			operator++(void);
		Fixed			operator++(int);
		Fixed &			operator--(void);
		Fixed			operator--(int);

	private:
	int					_num;
	static const int	_fb;

};

std::ostream &			operator<<( std::ostream & o, Fixed const & i );

#endif /* *********************************************************** FIXED_H */