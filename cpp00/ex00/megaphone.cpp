/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 22:17:34 by bnaji             #+#    #+#             */
/*   Updated: 2022/05/29 19:17:40 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>

int	main (int ac, char **av)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else {
		for(int i = 1; i < ac; i++){
			for(size_t j = 0; j < strlen(av[i]); j++) {
				putchar(toupper(av[i][j]));
			}
			if (i + 1 == ac)
				std::cout << std::endl;
		}
			
	}
}
