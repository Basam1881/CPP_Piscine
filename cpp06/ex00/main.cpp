/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:53:59 by bnaji             #+#    #+#             */
/*   Updated: 2022/05/23 10:45:30 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "TypeConverter.hpp"

int main(int ac, char **av) {
    if (ac != 2) {
        std::cerr << "Invalid Arguments" << std::endl;
        return (1);
    }
    TypeConverter   converter(av[1]);
    std::string str = av[1];
    if (converter.storeActualType(str))
        converter.convert2all();
    std::cout << converter;
    return 0;

}
