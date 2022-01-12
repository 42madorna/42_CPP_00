/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madorna- <madorna-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 06:52:28 by madorna-          #+#    #+#             */
/*   Updated: 2022/01/12 13:22:02 by madorna-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

int
	is_phone_number(const std::string str)
{
	for (int i = 0; str[i]; i++)
	{
		if (std::isdigit(str[i]) == 0)
			return (1);
	}
	if (str.length() != 9)
		return (2);
	return (0);
}

void
	ft_display_info(Contacts contact)
{
	std::cout << "First name: " << contact.f_name << std::endl;
	std::cout << "Last name: " << contact.l_name << std::endl;
	std::cout << "Nickname: " << contact.nickname << std::endl;
	std::cout << "Phone number: " << contact.phone << std::endl;
	std::cout << "Their darkest secret: " << contact.d_secret << std::endl;
}

void
	ft_search(PhoneBook *phone)
{
	char id;
	if (phone->contacts[0].l_name.empty())
	{
		std::cout << "Contact list empty, use ADD first" << std::endl;
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
		if (f_name.length() > 10)
		{
			f_name[9] = '.';
			f_name[10] = '\0';
		}
		l_name = phone->contacts[i].l_name;
		if (l_name.length() > 10)
		{
			l_name[9] = '.';
			l_name[10] = '\0';
		}
		nickname = phone->contacts[i].nickname;
		if (nickname.length() > 10)
		{
			nickname[9] = '.';
			nickname[10] = '\0';
		}
		printf("|%10d|%10s|%10s|%10s|\n", i, f_name.c_str(), l_name.c_str(), nickname.c_str());
	}
	printf("¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n");
	do
	{
		std::cout << "Enter an index: ";
		std::cin >> id;
		if ('0' > id || id > '7')
			std::cout << "Index range must be between 0 and 7" << std::endl;
		else
		{
			if (phone->contacts[id - '0'].f_name.empty())
			{
				std::cout << "Please enter an index that exists" << std::endl;
				id = -1;
				continue ;
			}
			ft_display_info(phone->contacts[id - '0']);
			break ;
		}
	} while ('0' > id || id > '7');
}

int
	ft_add(PhoneBook *phone)
{
	int i;
	int p_ret;

	for (i = 0; i < 8 && !phone->contacts[i].l_name.empty(); i++);
	if (i == 8)
	{
		std::cout << "List already full, oldest contact will be replaced" << std::endl;
		for (int a = 0; a < 7; a++)
			phone->contacts[a] = phone->contacts[a + 1];
		i = 7;
	}
	std::cin.clear();
	std::cin.ignore();
	do {
		std::cout << "Enter a name: ";
		std::getline(std::cin, phone->contacts[i].f_name);
	} while (phone->contacts[i].f_name.empty());
	do {
		std::cout << "Enter the lastname: ";
		std::getline(std::cin, phone->contacts[i].l_name);
	} while (phone->contacts[i].l_name.empty());
	do {
		std::cout << "Enter a nickname: ";
		std::getline(std::cin, phone->contacts[i].nickname);
	} while (phone->contacts[i].nickname.empty());
	do {
		std::cout << "Enter a phone number: ";
		std::getline(std::cin, phone->contacts[i].phone);
		if ((p_ret = is_phone_number(phone->contacts[i].phone)) != 0)
		{
			phone->contacts[i].phone.clear();
			if (p_ret == 1)
				std::cout << "Phone numbers can only contain numbers" <<  std::endl;
			if (p_ret == 2)
				std::cout << "Phone numbers must be 9 numbers long" << std::endl;
		}
	} while (phone->contacts[i].phone.empty());
	do {
		std::cout << "Enter their darkest secret: ";
		std::getline(std::cin, phone->contacts[i].d_secret);
	} while (phone->contacts[i].d_secret.empty());
	return (0);
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