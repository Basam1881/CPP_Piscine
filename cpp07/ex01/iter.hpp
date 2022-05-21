/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 16:24:48 by bnaji             #+#    #+#             */
/*   Updated: 2022/05/21 16:48:20 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <string>

template <typename T>
void	iter(T * arr, int len, void (*f)(T &)) {
	for (int i = 0; i < len; i++) {
    f(arr[i]);
  }
}

#endif /* ******************************************************** ITER_HPP */