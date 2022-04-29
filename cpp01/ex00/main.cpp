/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 17:28:11 by bnaji             #+#    #+#             */
/*   Updated: 2022/04/29 18:29:04 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
	Zombie	zombie;
	Zombie	*zAllen;

	zAllen = zombie.newZombie("Allan");
	zombie.randomChump("Yassir");
	delete 	zAllen;
	return (0);
}