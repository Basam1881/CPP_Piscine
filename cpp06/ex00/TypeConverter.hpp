/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TypeConverter.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 18:58:22 by bnaji             #+#    #+#             */
/*   Updated: 2022/09/14 12:00:21 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPECONVERTER_HPP
# define TYPECONVERTER_HPP

# include <iostream>
# include <sstream>
# include <string>
// # include <ctype.h>
# include <cstdlib>

class TypeConverter
{

	public:

		TypeConverter();
		TypeConverter(std::string str);
		TypeConverter( TypeConverter const & src );
		~TypeConverter();

		TypeConverter &		operator=( TypeConverter const & rhs );

		char const &				getCharVal() const;
		int const &					getIntVal() const;
		float const &				getFloatVal() const;
		double const &			getDoubleVal() const;
		std::string const &	getString() const;
		bool const &				getUndefined() const;
		bool const &				getPosInf() const;
		bool const &				getNegInf() const;
		char const &				getOrgVal() const;
		bool const &				getIsFractional() const;
		bool const &				getAllConverted() const;
		
		void				        convert2all();
		int					        checkNumbers(std::string str);
		int					        checkAfterDot(std::string str);
		int					        storeActualType(std::string str);
		void				        displayChar(std::ostream & o);
		void				        displayInt(std::ostream & o);
		void				        displayFloat(std::ostream & o);
		void				        displayDouble(std::ostream & o);

	private:
		char					      _cval;
		int						      _ival;
		float					      _fval;
		double				      _dval;
		std::string		      _str;
		bool					      _undifined;
		bool					      _posInf;
		bool					      _negInf;
		void					      _char2all();
		void					      _int2all();			
		void					      _float2all();				
		void					      _double2all();
		bool					      _isChar(std::string str);
		bool					      _isSpecial(std::string str);
		bool					      _isInt(std::string str);
		bool					      _isFloat(std::string str);
		bool					      _isDouble(std::string str);
		int						      _strCnt;
		char					      _orgVal;
		bool					      _isFractional;
		bool					      _allConverted;
		bool					      _isConvertedToChar;
		bool					      _isConvertedToInt;
};

std::ostream &			operator<<( std::ostream & o, TypeConverter const & i );

#endif /* *************************************************** TYPECONVERTER_H */