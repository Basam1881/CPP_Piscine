/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 00:35:41 by bnaji             #+#    #+#             */
/*   Updated: 2022/05/24 09:10:17 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <string>
# include <iterator>
# include <algorithm>

template <typename T>
typename T::iterator	easyfind(T & x, int & y) {
  return (find(x.begin(), x.end(), y));
}

#endif /* ******************************************************** EASYFIND_HPP */