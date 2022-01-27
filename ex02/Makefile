# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: madorna- <madorna-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/03 06:52:19 by madorna-          #+#    #+#              #
#    Updated: 2022/01/27 20:51:51 by madorna-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	tests.cpp																\
		Account.cpp

NAME =	account
INCLUDES =	Account.hpp

CC = c++
CFLAGS = -Wall -Wextra -std=c++98 #-Werror

$(NAME): ./$(SRCS)
	$(CC) $(SRCS) $(CFLAGS) -o $(NAME)

all: $(NAME)

clean:

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
