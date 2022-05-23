/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 16:42:38 by bnaji             #+#    #+#             */
/*   Updated: 2022/05/23 20:51:26 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"
#include <ctype.h>
#include <string.h>

void  mult(int & n) {
  n *= 2;
}

void  div(int & n) {
  n /= 2;
}

void  inc(int & n) {
  n++;
}

void  dec(int & n) {
  n--;
}

void  allX(char & c) {
  if (isalpha(c))
    c = 'X';
}

void  printIntArr(int *a, int n) {
  std::cout << "[ ";
  for (int i = 0; i < n; i++) {
    std::cout << a[i];
    if (i + 1 != n)
      std::cout << ", ";
  }
  std::cout << " ]" << std::endl;
}

int main () {
  int n= 3;
  int a[] = {5, 10 ,15};
  printIntArr(a, n);
  iter<int> (a, n, &mult);
  printIntArr(a, n);
  iter<int> (a, n, &inc);
  printIntArr(a, n);
  iter<int> (a, n, &dec);
  printIntArr(a, n);
  iter<int> (a, n, &div);
  printIntArr(a, n);
  std::cout << "--------------------------------" << std::endl;
  char str[] = "Hello World";
  std::cout << "str: " << str << std::endl;
  iter<char> (str, strlen(str), &allX);
  std::cout << "str: " << str << std::endl;
}
