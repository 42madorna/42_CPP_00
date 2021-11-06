# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: madorna- <madorna-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/03 06:52:19 by madorna-          #+#    #+#              #
#    Updated: 2021/11/06 13:24:48 by madorna-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	main.cpp

NAME =	ft_phonebook
INCLUDES =	Contacts.hpp PhoneBook.hpp

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

$(NAME): ./$(SRCS)
	$(CC) $(SRCS) $(CFLAGS) -o $(NAME)

all: $(NAME)

clean:

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
