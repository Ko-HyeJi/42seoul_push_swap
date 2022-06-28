# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyko <hyko@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/23 19:49:42 by hyko              #+#    #+#              #
#    Updated: 2022/06/28 17:21:52 by hyko             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = $(addprefix ./srcs/, push_swap.c\
push_swap_utils.c\
stack.c\
ft_split.c\
operation_swap.c\
operation_push.c\
operation_rotate.c\
operation_reverse_rotate.c\
sort.c\)

all :
	cc $(SRCS)