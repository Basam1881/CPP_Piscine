/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 12:46:23 by bnaji             #+#    #+#             */
/*   Updated: 2022/05/23 02:43:37 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Span.hpp"
#include <exception>


int main () {
  Span   span1(5);

  try { span1.addNumber(6); }
  catch(Span::IsFullException & e) { std::cout << e.what() << std::endl; }
  try { span1.addNumber(3); }
  catch(Span::IsFullException & e) { std::cout << e.what() << std::endl; }
  try { span1.addNumber(17); }
  catch(Span::IsFullException & e) { std::cout << e.what() << std::endl; }
 
  std::vector<int>::const_iterator it1 = span1.getBegin();
  std::vector<int>::const_iterator it2 = span1.getEnd();
  // int arr[] = {1, 2, 4, 5, 6};
  
  Span span2;
  span2.fillSpan(it1, it2);

  
  // try { span1.addNumber(9); }
  // catch(Span::IsFullException & e) { std::cout << e.what() << std::endl; }
  // try { span1.addNumber(11); }
  // catch(Span::IsFullException & e) { std::cout << e.what() << std::endl; }
  // try { span1.addNumber(5); }
  // catch(Span::IsFullException & e) { std::cout << e.what() << std::endl; }
  
  std::cout << "Span1: " << span1 << std::endl;
  std::cout << "Span2: " << span2 << std::endl << std::endl;

  try {
    std::cout << "Shortest Span: " << span1.shortestSpan() << std::endl;
  }
  catch (Span::NotEnoughElementsException & e) {
    std::cout << e.what() << std::endl;
  }
  try {
    std::cout << "Longest  Span: " << span2.longestSpan() << std::endl;
  }
  catch (Span::NotEnoughElementsException & e) {
    std::cout << e.what() << std::endl;
  }
}
