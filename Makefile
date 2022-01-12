# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: madorna- <madorna-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/12 05:40:57 by madorna-          #+#    #+#              #
#    Updated: 2022/01/12 05:43:32 by madorna-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Makefile to clean everything

fclean:
	make -C ex00 fclean
	make -C ex01 fclean
	make -C ex02 fclean

.PHONY: fclean