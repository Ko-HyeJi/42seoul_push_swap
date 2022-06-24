# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyko <hyko@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/23 19:49:42 by hyko              #+#    #+#              #
#    Updated: 2022/06/25 01:04:25 by hyko             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = push_swap.c\
push_swap_utils.c\
stack.c\
ft_split.c\
operation_swap.c\
operation_push.c\
operation_rotate.c\
operation_reverse_rotate.c\

all :
	gcc $(SRCS)