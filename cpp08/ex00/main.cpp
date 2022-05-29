/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 00:56:47 by bnaji             #+#    #+#             */
/*   Updated: 2022/05/29 19:19:32 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iterator>
#include <list>
#include <vector>
#include "easyfind.hpp"

template <typename T>
void    printAll(T & x) {
  std::cout << "[ ";
  typename T::const_iterator it;
  for (it = x.begin(); it != x.end(); it++) {
    std::cout << *(it);
    it++;
    if (it != x.end())
      std::cout << ", ";
    it--;
  }
  std::cout << " ]" << std::endl;
}

template <typename T>
void      deleteAllOccurance(T & x, int n) {
  while (true) {
    typename T::iterator it = easyfind< T >(x, n);
    if (it != x.end())
      x.erase(it);
    else
      break ;
  }
}

int main () {
  std::list<int>    list;
  std::vector<int>  vector;
  int n = 5;
  int m = 15;
  
  std::cout << std::endl << "------------------- List -------------------" << std::endl;
  list.push_back(5);
  list.push_back(10);
  list.push_back(15);
  list.push_back(15);
  list.push_front(15);
  printAll< std::list<int> >(list);
  deleteAllOccurance< std::list<int> >(list, n);
  printAll< std::list<int> >(list);
  deleteAllOccurance< std::list<int> >(list, m);
  printAll< std::list<int> >(list);
  
  std::cout << std::endl << "------------------- Vector -------------------" << std::endl;
  vector.push_back(5);
  vector.push_back(15);
  vector.push_back(10);
  vector.push_back(15);
  vector.push_back(15);
  printAll< std::vector<int> >(vector);
  deleteAllOccurance< std::vector<int> >(vector, n);
  printAll< std::vector<int> >(vector);
  deleteAllOccurance< std::vector<int> >(vector, m);
  printAll< std::vector<int> >(vector);
  std::cout << std::endl;
}
