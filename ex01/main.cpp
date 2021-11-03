/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madorna- <madorna-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 06:52:28 by madorna-          #+#    #+#             */
/*   Updated: 2021/11/03 10:11:18 by madorna-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contacts.hpp"

void
	add(Contactss *contact)
{
	int i;

	for (i = 0; i < 8 && !contact[i].l_name.empty(); i++);
	if (i == 8)
	{
		std::cout << "Llist already full, oldest contact will be replaced" << std::endl;
		for (int a = 7; a > 0; a--)
			contact[a - 1] = contact[a];
		i = 7;
	}
	std::cout << "Enter a name: ";
	std::cin >> contact[i].f_name;
	std::cout << "Enter the lastname: ";
	std::cin >> contact[i].l_name;
	std::cout << "Enter a nickname: ";
	std::cin >> contact[i].nickname;
	std::cout << "Enter a phone number: ";
	std::cin >> contact[i].phone;
	std::cout << "Enter their darkest secret: ";
	std::cin >> contact[i].d_secret;
}

int
	main()
{
	Contactss contact[8];
	int i = 7;
	std::cout << "Welcome to ft_phonebook 📒" << std::endl;
	for (int a = 0; a < 8; a++)
	{
		contact[a].f_name = "pepe";
		contact[a].l_name = "pepe";
		contact[a].nickname = "pepe";
		contact[a].phone = a;
		contact[a].d_secret = "secreto";
	}
	while (1)
	{
		std::string action;
		std::cout << "What do you want to do? ";
		std::cin >> action;
		if (action == "EXIT" || action == "\0")
		{
			std::cout << (action == "\0" ? "\n" : "") << "Bye" << std::endl;
			break ;
		}
		else if (action == "ADD")
		{
			add(contact);
			std::cout << "Contact " << i << " " << contact[i].f_name << " " << contact[i].l_name << " " << contact[i].phone << " added" << std::endl;
			i = i == 7 ? 7 : i + 1;
		}
		else if (action == "SEARCH")
		{
			std::cout << "TODO: call search funcion" << std::endl;
		}
		else
			std::cout << "Invalid option. Valid ones are: EXIT, ADD, SEARCH" << std::endl;
	}
	return (0);
}