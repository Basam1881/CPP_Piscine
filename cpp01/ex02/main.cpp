/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 17:25:02 by bnaji             #+#    #+#             */
/*   Updated: 2022/04/29 21:34:43 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main() {
	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;

	std::cout << "str    add: " << &str << std::endl;
	std::cout << "strptr add: " << stringPTR << std::endl;
	std::cout << "strref add: " << &stringREF << std::endl << std::endl;
	std::cout << "str   : " << str << std::endl;
	std::cout << "strptr: " << *stringPTR << std::endl;
	std::cout << "strref: " << stringREF << std::endl;
}
