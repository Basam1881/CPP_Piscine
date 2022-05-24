/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 12:46:23 by bnaji             #+#    #+#             */
/*   Updated: 2022/05/24 09:47:17 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Span.hpp"
#include <exception>


int main () {
  Span   span1(5);

  span1.addNumber(6);
  span1.addNumber(3);
  span1.addNumber(17);
  span1.addNumber(9);
  span1.addNumber(11);
  span1.addNumber(5);
  // std::vector<int>::const_iterator it1 = span1.getBegin();
  // std::vector<int>::const_iterator it2 = span1.getEnd();
  // int arr[] = {1, 2, 4, 5, 6};
  
  Span span2(span1);
  // span2.fillSpan(it1, it2);

  
  
  std::cout << "Span1: " << span1 << std::endl;
  std::cout << "Span2: " << span2 << std::endl << std::endl;

  std::cout << "Shortest Span: " << span1.shortestSpan() << std::endl;
  std::cout << "Longest  Span: " << span2.longestSpan() << std::endl;
}
