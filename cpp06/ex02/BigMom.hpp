/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BigMom.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 19:51:05 by bnaji             #+#    #+#             */
/*   Updated: 2022/05/20 20:22:44 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIGMOM_HPP
# define BIGMOM_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <exception>

class Base { public: virtual ~Base() {} };

class A : public Base {};

class B : public Base {};

class C : public Base {};

class BigMom
{

	public:

		BigMom();
		BigMom( BigMom const & src );
		~BigMom();

		Base *	generate(void);
		void		identify(Base* p);
		void		identify(Base& p);
		
		Base *&				getBaseRef() const;
		Base *				getBasePtr() const;
		bool					setBasePtr(Base * base);
		bool					testNumBases(int n);

		BigMom &		operator=( BigMom const & rhs );

	private:
		Base *			_basePtr;
  	Base *&			_baseRef;

};

#endif /* ********************************************************** BIGMOM_H */