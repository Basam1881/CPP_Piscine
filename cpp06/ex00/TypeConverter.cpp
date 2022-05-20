/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TypeConverter.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 18:58:16 by bnaji             #+#    #+#             */
/*   Updated: 2022/05/20 10:48:45 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TypeConverter.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

TypeConverter::TypeConverter() : _cval('\0'), _ival(0), _fval(0.0f), _dval(0.0), _str(""), _undifined(false), _posInf(false),
	_negInf(false), _strCnt(0), _orgVal('\0'), _isFractional(false), _allConverted(false) {
}

TypeConverter::TypeConverter(std::string str) : _cval('\0'), _ival(0), _fval(0.0f), _dval(0.0), _str(str), _undifined(false), _posInf(false),
 _negInf(false), _strCnt(0), _orgVal('\0'), _isFractional(false), _allConverted(false) {
}

TypeConverter::TypeConverter( const TypeConverter & src ) {
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

TypeConverter::~TypeConverter() {
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

TypeConverter &				TypeConverter::operator=( TypeConverter const & rhs )
{
	if ( this != &rhs )
	{
		this->_cval = rhs.getCharVal();
		this->_ival = rhs.getIntVal();
		this->_fval = rhs.getFloatVal();
		this->_dval = rhs.getDoubleVal();
		this->_str = rhs.getString();
		this->_undifined = rhs.getUndefined();
		this->_posInf = rhs.getPosInf();
		this->_negInf = rhs.getNegInf();
		this->_orgVal = rhs.getOrgVal();
		this->_isFractional = rhs.getIsFractional();
		this->_allConverted = rhs.getAllConverted();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, TypeConverter const & i )
{
	if (!i.getOrgVal() || !i.getAllConverted()) {
		o << "Error: Input is either invalid or not converted to all types yet" << std::endl;
		return o;
	}
	static_cast<TypeConverter>(i).displayChar(o);
	static_cast<TypeConverter>(i).displayInt(o);
	static_cast<TypeConverter>(i).displayFloat(o);
	static_cast<TypeConverter>(i).displayDouble(o);
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void				TypeConverter::displayChar(std::ostream & o) {
	if (!this->getOrgVal() || !this->getAllConverted())
		return ;
	o << "char = ";
	if (this->getOrgVal() == 's' || (this->getIsFractional()))
		o << "Impossible" << std::endl;
	else if (this->getCharVal() < 33 || this->getCharVal() > 126)
		o << "Non displayable" << std::endl;
	else
		o << "'" << this->getCharVal() << "'" <<  std::endl;
}

void				TypeConverter::displayInt(std::ostream & o) {
	if (!this->getOrgVal() || !this->getAllConverted())
		return ;
	o << "int = ";
	if (this->getOrgVal() == 's')
		o << "Impossible" << std::endl;
	else
		o << this->getIntVal() << std::endl;
}

void				TypeConverter::displayFloat(std::ostream & o) {	
	if (!this->getOrgVal() || !this->getAllConverted())
		return ;
	o << "float = ";
	if (this->getOrgVal() == 's') {
		if (this->getUndefined())
			o << "nonf" << std::endl;
		else if (this->getPosInf())
			o << "+inff" << std::endl;
		else if (this->getNegInf())
			o << "-inff" << std::endl;
	}
	else {
		o << this->getFloatVal();
		if (this->getIsFractional())
			o << "f" << std::endl;
		else
			o << ".0f" << std::endl;
	}
}

void				TypeConverter::displayDouble(std::ostream & o) {
	if (!this->getOrgVal() || !this->getAllConverted())
		return ;
	o << "double = ";
	if (this->getOrgVal() == 's') {
		if (this->getUndefined())
			o << "non" << std::endl;
		else if (this->getPosInf())
			o << "+inf" << std::endl;
		else if (this->getNegInf())
			o << "-inf" << std::endl;
	}
	else {
		o << this->getFloatVal();
		if (!this->getIsFractional())
			o << ".0";
		std::cout << std::endl;
	}
}


bool				TypeConverter::_isChar(std::string str) {
	if (str.length() == 1 && str.find_first_of("0123456789", 0 ) == std::string::npos) {
		this->_cval = str[0];
		this->_orgVal = 'c';
		return true;
	}
	return false;
}

bool				TypeConverter::_isSpecial(std::string str) {
	if (!str.compare("nan") || !str.compare("nanf"))
		this->_undifined = true;
	else if (!str.compare("+inf") || !str.compare("+inff"))
		this->_posInf = true;
	else if (!str.compare("-inf") || !str.compare("-inff"))
		this->_negInf = true;
	if (this->_undifined || this->_posInf || this->_negInf) {
		this->_orgVal = 's';
		this->_allConverted = true;
		return true;
	}
	return false;
}

bool				TypeConverter::_isInt(std::string str) {
	if (str.length() == static_cast<long unsigned int>(this->_strCnt)) {
		std::stringstream s(str);
		s >> this->_ival;
		this->_orgVal = 'i';
		return true;
	}
	return false;
}

bool				TypeConverter::_isFloat(std::string str) {
	if (str.length() == static_cast<long unsigned int>(this->_strCnt) + 1 && str[this->_strCnt] == 'f') {
		std::stringstream s(str);
		s >> this->_fval;
		if (this->_fval != static_cast<int>(this->_fval))
			this->_isFractional = true;
		this->_orgVal = 'f';
		return true;
	}
	return false;
}

bool				TypeConverter::_isDouble(std::string str) {
	if (str.length() == static_cast<long unsigned int>(this->_strCnt)) {
		std::stringstream s(str);
		s >> this->_dval;
		if (this->_dval != static_cast<int>(this->_dval))
			this->_isFractional = true;
		this->_orgVal = 'd';
		return true;
	}
	return false;
}

int					TypeConverter::storeActualType(std::string str) {
	if (this->_str.empty())
		return 0;
	if (this->_isChar(str))
		return 1;
	else {
		if (this->_isSpecial(str))
			return 5;
		if (str[0] == '+' || str[0] == '-')
			this->_strCnt++;
		int prevCnt = this->_strCnt;
		while (str[this->_strCnt] >= '0' && str[this->_strCnt] <= '9')
			this->_strCnt++;
		if (this->_strCnt == prevCnt)
			return 0;
		if (this->_isInt(str))
			return 2;
		else if (str[this->_strCnt] != '.') {
			return 0;
		}
		else {
			prevCnt = ++this->_strCnt;
			while (str[this->_strCnt] >= '0' && str[this->_strCnt] <= '9')
				this->_strCnt++;
			if (this->_strCnt == prevCnt)
				return 0;
			else if (this->_isDouble(str))
				return 4;
			else if (this->_isFloat(str))
				return 3;
		}
	}
	return 0;
}

void	TypeConverter::char2all() {
	if (this->_orgVal == 'c') {
		this->_ival = static_cast<int>(this->_cval);
		this->_fval = static_cast<float>(this->_cval);
		this->_dval = static_cast<double>(this->_cval);
		this->_allConverted = true;
	}
}
void	TypeConverter::int2all() {
	if (this->_orgVal == 'i') {
		if (this->_ival > 32 && this->_ival < 127)
			this->_cval = static_cast<char>(this->_ival);
		this->_fval = static_cast<float>(this->_ival);
		this->_dval = static_cast<double>(this->_ival);
		this->_allConverted = true;
	}
}
void	TypeConverter::float2all() {
	if (this->_orgVal == 'f') {
		if (!this->_isFractional && this->_fval > 32 && this->_fval < 127)
			this->_cval = static_cast<char>(this->_fval);
		this->_ival = static_cast<int>(this->_fval);
		this->_dval = static_cast<double>(this->_fval);
		this->_allConverted = true;
	}
}
void	TypeConverter::double2all() {
	if (this->_orgVal == 'd') {
		if (!this->_isFractional && this->_dval > 32 && this->_dval < 127)
			this->_cval = static_cast<char>(this->_dval);
		this->_ival = static_cast<int>(this->_dval);
		this->_fval = static_cast<double>(this->_dval);
		this->_allConverted = true;
	}
}

void				TypeConverter::convert2all() {
	this->char2all();
	this->int2all();
	this->float2all();
	this->double2all();
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

char const &		TypeConverter::getOrgVal() const {
	return (this->_orgVal);
}

char const &		TypeConverter::getCharVal() const {
	return (this->_cval);
}

int const &			TypeConverter::getIntVal() const {
	return (this->_ival);
}

float const &		TypeConverter::getFloatVal() const {
	return (this->_fval);
}

double const &	TypeConverter::getDoubleVal() const {
	return (this->_dval);
}

std::string const &	TypeConverter::getString() const {
	return (this->_str);
}

bool const &	TypeConverter::getIsFractional() const {
	return (this->_isFractional);
}

bool const &	TypeConverter::getAllConverted() const {
	return (this->_allConverted);
}

bool const &	TypeConverter::getUndefined() const {
	return (this->_undifined);
}

bool const &	TypeConverter::getPosInf() const {
	return (this->_posInf);
}

bool const &	TypeConverter::getNegInf() const {
	return (this->_negInf);
}


/* ************************************************************************** */