/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 17:16:18 by bnaji             #+#    #+#             */
/*   Updated: 2022/05/21 18:39:28 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>
# include <cstdlib>

template <typename T>
class Array
{

	public:

		Array() : _arr(NULL), _size(1) {
			this->_arr = new T;
		}
		Array(unsigned int n) : _arr(NULL), _size(n) {
			this->_arr = new T[n];
		}
		Array( Array const & src ) {
			*this = src;
		}
		~Array() {
			delete [] this->_arr;
		}

		T	const *								getArray() const {
			return (this->_arr);
		}
		unsigned int const &		size() const{
			return (this->_size);
		}

		T &			operator[](unsigned int index) {
			try{
				if (index >= this->_size)
					throw Array::OutOfBounds();
				else
					return (this->_arr[index]);
			}
			catch (OutOfBounds & e) {
				std::cerr << e.what() << std::endl;
				exit (1);
			}
			return (*this->_arr);
		}
		Array &		operator=( Array const & rhs ) {
			this->_size = rhs.size();
			this->_arr = new T[this->_size];
			for (unsigned int i = 0; i < this->_size; i++) {
				this->_arr[i] = rhs.getArray()[i];
			}
			return *this;
		}

		class OutOfBounds : public std::exception
		{
			public:
				virtual const char *	what() const throw() {
					return ("Error: Bad Access to Array class.");
				}
		};

	private:
		T	*							_arr;
		unsigned int		_size;

};

std::ostream &			operator<<( std::ostream & o, Array<char> const & i ) {
	for (unsigned int ind = 0; ind < i.size(); ind++) {
		o << i.getArray()[ind];
	}
	return o;
}

template <typename T>
std::ostream &			operator<<( std::ostream & o, Array<T> const & i ) {
	o << "[ ";
	for (unsigned int ind = 0; ind < i.size(); ind++) {
		o << i.getArray()[ind];
		if (ind < i.size() - 1)
			o << ", ";
	}
	o << " ]";
	return o;
}


#endif /* *********************************************************** ARRAY_H */