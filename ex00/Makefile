# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: madorna- <madorna-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/03 06:40:30 by madorna-          #+#    #+#              #
#    Updated: 2021/11/03 06:45:52 by madorna-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = megaphone.cpp

NAME = ex00

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

$(NAME): ./$(SRCS)
	$(CC) $(SRCS) $(CFLAGS) -o $(NAME)

clean:

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re