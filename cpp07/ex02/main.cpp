/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 17:21:53 by bnaji             #+#    #+#             */
/*   Updated: 2022/05/21 18:40:11 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

int main () {
  Array<char> str1(5);
  str1[0] = 'H';
  str1[1] = 'e';
  str1[2] = 'l';
  str1[3] = 'l';
  str1[4] = 'o';
  Array<char> str2(str1);
  std::cout << "str1: " << str1 << std::endl;
  std::cout << "str2: " << str2 << std::endl << std::endl;
  Array<float> arr1(3);
  arr1[0] = 5.5f;
  arr1[1] = 20.2f;
  arr1[2] = 15.0f;
  Array<float> arr2;
  arr2 = arr1;
  std::cout << "arr1: " << arr1 << std::endl;
  std::cout << "arr2: " << arr2 << std::endl << std::endl;
}
