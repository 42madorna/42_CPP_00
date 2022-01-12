/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madorna- <madorna-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 06:52:28 by madorna-          #+#    #+#             */
/*   Updated: 2022/01/12 05:50:30 by madorna-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

void
	ft_display_info(Contacts contact)
{
	std::cout << contact.f_name << std::endl;
	std::cout << contact.l_name << std::endl;
	std::cout << contact.nickname << std::endl;
	std::cout << contact.phone << std::endl;
	std::cout << contact.d_secret << std::endl;
}

void
	ft_search(PhoneBook *phone)
{
	int id;
	if (phone->contacts[0].l_name.empty())
	{
		std::cout << "Contact list empty" << std::endl;
		return ;
	}
	printf("_____________________________________________\n");
	printf("|%10s|%10s|%10s|%10s|\n", "Index", "First name", "Last name", "Nickname");
	printf("|¯¯¯¯¯¯¯¯¯¯|¯¯¯¯¯¯¯¯¯¯|¯¯¯¯¯¯¯¯¯¯|¯¯¯¯¯¯¯¯¯¯|\n");
	for (int i = 0; i < 8 && !phone->contacts[i].l_name.empty(); i++)
	{
		std::string f_name;
		std::string l_name;
		std::string nickname;

		f_name = phone->contacts[i].f_name;
		if (std::strlen(f_name.c_str()) > 10)
		{
			f_name[9] = '.';
			f_name[10] = '\0';
		}
		l_name = phone->contacts[i].l_name;
		if (std::strlen(l_name.c_str()) > 10)
		{
			l_name[9] = '.';
			l_name[10] = '\0';
		}
		nickname = phone->contacts[i].nickname;
		if (std::strlen(nickname.c_str()) > 10)
		{
			nickname[9] = '.';
			nickname[10] = '\0';
		}
		printf("|%10d|%10s|%10s|%10s|\n", i, f_name.c_str(), l_name.c_str(), nickname.c_str());
	}
	printf("¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n");
	while (!std::cin.eof())
	{
		std::cout << "Enter an index: ";
		std::cin >> id;
		// if (id == '\0')
		// 	break ;
		if (0 > id || id > 7)
			std::cout << "Index range must be between 0 and 7" << std::endl;
		else
		{
			ft_display_info(phone->contacts[id]);
			break ;
		}
	}
}

int
	ft_add(PhoneBook *phone)
{
	int i;

	for (i = 0; i < 8 && !phone->contacts[i].l_name.empty(); i++);
	if (i == 8)
	{
		std::cout << "List already full, oldest contact will be replaced" << std::endl;
		for (int a = 0; a < 7; a++)
			phone->contacts[a] = phone->contacts[a + 1];
		i = 7;
	}
	// TODO: Error check
	while (!std::cin.eof())
	{
		std::cout << "Enter a name: ";
		std::cin.ignore();
		std::getline(std::cin, phone->contacts[i].f_name);
		std::cout << "Enter the lastname: ";
		std::getline(std::cin, phone->contacts[i].l_name);
		std::cout << "Enter a nickname: ";
		std::getline(std::cin, phone->contacts[i].nickname);
		// FIXME: Infinite loop when entering text
		std::cout << "Enter a phone number: ";
		std::cin >> phone->contacts[i].phone;
		std::cout << "Enter their darkest secret: ";
		std::cin.ignore();
		std::getline(std::cin, phone->contacts[i].d_secret);
		if (phone->contacts[i].f_name.empty() || phone->contacts[i].l_name.empty()
			|| phone->contacts[i].nickname.empty() || !phone->contacts[i].phone
			|| phone->contacts[i].d_secret.empty())
		{
			bzero(&phone->contacts[i], sizeof(Contacts));
			std::cout << "Sorry, some info was empty, try again...";
			continue ;
		}
		return (0);
	}
	std::cin.clear();
	std::cin.ignore();
	return (1);
}

int
	main()
{
	PhoneBook phone;
	int i = 7;

	std::cout << "Welcome to ft_phonebook 📒" << std::endl;
	// // TODO: Delete this
	// for (int a = 0; a < 8; a++)
	// {
	// 	contact[a].f_name = "pepepepepepepepe";
	// 	contact[a].l_name = "pepepepepepepepe";
	// 	contact[a].nickname = "pepepepepepepepe";
	// 	contact[a].phone = a;
	// 	contact[a].d_secret = "secreto";
	// }
	// // 
	while (true)
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
			if (!ft_add(&phone))
			{
				std::cout << "New contact added" << std::endl;
				i = i == 7 ? 7 : i + 1;
			}
		}
		else if (action == "SEARCH")
			ft_search(&phone);
		else
			std::cout << "Invalid option. Valid ones are: EXIT, ADD, SEARCH" << std::endl;
	}
	return (0);
}