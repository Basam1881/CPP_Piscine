/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 12:46:23 by bnaji             #+#    #+#             */
/*   Updated: 2022/05/24 18:36:54 by bnaji            ###   ########.fr       */
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
  std::cout << "Span1: " << span1 << std::endl;
  std::cout << "Shortest Span: " << span1.shortestSpan() << std::endl;
  std::cout << "Longest  Span: " << span1.longestSpan() << std::endl << std::endl;

  unsigned int i = 1;
  std::vector<int>    vec1(3, i++);
  std::vector<int>    vec2(3, i++);
  std::vector<int>    vec3(3, i++);
  std::vector<int>    vec4(3, i++);
  std::vector<int>    vec5(3, i++);
  Span span2(15);
  span2.fillSpan(vec1.begin(), vec1.end());
  span2.fillSpan(vec2.begin(), vec2.end());
  span2.fillSpan(vec3.begin(), vec3.end());
  span2.fillSpan(vec4.begin(), vec4.end());
  span2.fillSpan(vec5.begin(), vec5.end());
  span2.fillSpan(vec5.begin(), vec5.end());
  std::cout << "Span2: " << span2 << std::endl;
  std::cout << "Shortest Span: " << span2.shortestSpan() << std::endl;
  std::cout << "Longest  Span: " << span2.longestSpan() << std::endl << std::endl;

  std::vector<int>    vec6(1000000, 1);
  Span span3(1000000);
  span3.addNumber(12);
  span3.fillSpan(vec6.begin(), vec6.end());
  // std::cout << "Span3: " << span3 << std::endl;
  std::cout << "Span3: " << "begin: " << *span3.getBegin() << "\tend: " << *(--span3.getEnd()) << std::endl;
}
