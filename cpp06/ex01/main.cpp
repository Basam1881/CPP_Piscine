/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 13:25:46 by bnaji             #+#    #+#             */
/*   Updated: 2022/05/20 15:14:08 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serialization.hpp"

int main () {
  Serialization serialization;
  Serialization::Data sender;
  sender.str = "Hello from sender";
  sender.num = 22;
  serialization.setUIntPtr(serialization.serialize(&sender));
  serialization.setReceiver(serialization.deserialize(serialization.getUIntPtr()));
  std::cout << "Sender   Ptr: " << &sender << std::endl;
  std::cout << "Receiver Ptr: " << serialization.getReceiver() << std::endl << std::endl;
  std::cout << "sent     Str: " << sender.str << std::endl;
  std::cout << "Received Str: " << serialization.getReceiver()->str << std::endl << std::endl;
  std::cout << "sent     Num: " << sender.num << std::endl;
  std::cout << "Received Num: " << serialization.getReceiver()->num << std::endl << std::endl;;

  std::cout << "-------------------- Extra Test W Void -----------------------" << std::endl << std::endl;
  void * pp = reinterpret_cast<void *>(&sender);
  Serialization::Data * receiver = reinterpret_cast<Serialization::Data *>(pp);
  std::cout << "Sender   Ptr: " << &sender << std::endl;
  std::cout << "Receiver Ptr: " << receiver << std::endl << std::endl;
  std::cout << "sent     Str: " << sender.str << std::endl;
  std::cout << "Received Str: " << receiver->str << std::endl << std::endl;
  std::cout << "sent     Num: " << sender.num << std::endl;
  std::cout << "Received Num: " << receiver->num << std::endl;
}
