/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 23:25:14 by bnaji             #+#    #+#             */
/*   Updated: 2022/05/16 12:53:51 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	int n = 4;
	AAnimal* animals[n];
	for (int i = 0; i < n; i++) {
		if (i < n / 2)
			animals[i] = new Cat;
		else
			animals[i] = new Dog;
	}
	for (int i = 0; i < n; i++) {
		animals[i]->makeSound();
	}
	for (int i = 0; i < n; i++) {
		delete animals[i];
	}
	return 0;
}
