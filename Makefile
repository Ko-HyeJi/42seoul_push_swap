# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyko <hyko@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/23 19:49:42 by hyko              #+#    #+#              #
#    Updated: 2022/06/26 01:36:47 by hyko             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = push_swap.c\
push_swap_utils.c\
stack.c\
ft_split.c\
operation_swap.c\
operation_push.c\
operation_rotate.c\
operation_reverse_rotate.c\
sort.c\

all :
	gcc $(SRCS)