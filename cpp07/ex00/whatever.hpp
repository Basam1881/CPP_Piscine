/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 14:42:30 by bnaji             #+#    #+#             */
/*   Updated: 2022/05/21 16:23:14 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>
# include <string>

template <typename T>
void	swap(T & x, T & y) {
	T tmp = x;
	x = y;
	y = tmp;
}

template <typename T>
T const &		min(T const & x, T const & y) {
	return ((x < y) ? x : y);
}

template <typename T>
T const &		max(T const & x, T const & y) {
	return ((x > y) ? x : y);
}

#endif /* ******************************************************** WHATEVER_H */