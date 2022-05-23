/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 00:35:41 by bnaji             #+#    #+#             */
/*   Updated: 2022/05/22 12:33:48 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <string>
# include <iterator>

template <typename T>
typename T::iterator	easyfind(T & x, int & y) {
  typename T::iterator    it;
  for (it = x.begin(); it != x.end(); it++) {
    if (*it == y)
      return (it);
  }
  return (x.end());
}

#endif /* ******************************************************** EASYFIND_HPP */