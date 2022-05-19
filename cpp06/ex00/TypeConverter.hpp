/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TypeConverter.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 18:58:22 by bnaji             #+#    #+#             */
/*   Updated: 2022/05/18 19:38:07 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPECONVERTER_HPP
# define TYPECONVERTER_HPP

# include <iostream>
# include <string>

class TypeConverter
{

	public:

		TypeConverter();
		TypeConverter(std::string str);
		TypeConverter( TypeConverter const & src );
		~TypeConverter();

		TypeConverter &		operator=( TypeConverter const & rhs );

		char const &		getCharVal() const;
		int const &			getIntVal() const;
		float const &		getFloatVal() const;
		double const &		getDoubleVal() const;
		int					convert2Int();
		char;


	private:
		int					char2Int(char i);
		float				char2Float(char i);
		double				char2Double(char i);
		char				int2Char(int i);
		float				int2Float(int i);
		double				int2Double(int i);
		char				Float2Char(float i);
		int					Float2Int(float i);
		double				Float2Double(float i);
		char				double2Char(double i);
		int					double2Int(double i);
		float				double2Float(double i);
		char 				_cval;
		int					_ival;
		float				_fval;
		double				_dval;
		std::string			_str;

};

std::ostream &			operator<<( std::ostream & o, TypeConverter const & i );

typedef 

#endif /* *************************************************** TYPECONVERTER_H */