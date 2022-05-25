/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 18:13:36 by bnaji             #+#    #+#             */
/*   Updated: 2022/05/25 00:23:47 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "MutantStack.hpp"

int main () {
  MutantStack<int> mstack;
  std::cout << "------------------- Push 2 elements -------------------" << std::endl;
  mstack.push(5);
  mstack.push(17);
  std::cout << "top: " << mstack.top() << std::endl;
  std::cout << "size: " << mstack.size() << std::endl;
  std::cout << mstack << std::endl << std::endl;
  
  std::cout << "------------------- pop 1 element -------------------" << std::endl;
  mstack.pop();
  std::cout << "top: " << mstack.top() << std::endl;
  std::cout << "size: " << mstack.size() << std::endl;
  std::cout << mstack << std::endl << std::endl;
  
  std::cout << "------------------- Push 3 elements -------------------" << std::endl;
  mstack.push(3);
  mstack.push(5);
  mstack.push(737);
  std::cout << "First: " << *mstack.begin() << std::endl;
  std::cout << "Last: " << *(--mstack.end()) << std::endl;
  std::cout << mstack << std::endl << std::endl;
  
  std::cout << "------------------- Iterator check -------------------" << std::endl;
  MutantStack<int>::iterator it = mstack.begin();
  MutantStack<int>::iterator ite = mstack.end();
  std::cout << "First: " << *it << std::endl;
  ++it;
  std::cout << "Second: " << *it << std::endl;
  --it;
  std::cout << "First: " << *it << std::endl;
  it++;
  std::cout << "Second: " << *it << std::endl;
  it--;
  std::cout << "First: " << *it << std::endl;
  int i = 0;
  while (it != ite)
  {
    std::cout << ++i << ": " << *it << std::endl;
    ++it;
  }
  std::cout << std::endl;
  
  MutantStack<int> stack1(mstack);
  std::cout << "------------------- Copy Constructor check -------------------" << std::endl;
  std::cout << stack1 << std::endl << std::endl;
  
  std::cout << "------------------- Copy Assignement Operator check -------------------" << std::endl;
  MutantStack<int> stack2;
  stack2 = stack1;
  std::cout << stack2 << std::endl << std::endl;
  
  std::stack<int> stack3(mstack);
  std::cout << "------------------- Copy to stack check -------------------" << std::endl;
  std::cout << stack3.top() << std::endl << std::endl;
}
