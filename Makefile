# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyko <hyko@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/23 19:49:42 by hyko              #+#    #+#              #
#    Updated: 2022/06/29 20:18:20 by hyko             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS = checker

CC = cc
CFLAG = -Wall -Wextra -Werror
RM = rm -rf

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

SRC = $(addprefix ./src/, push_swap.c\
push_swap_utils.c\
stack.c\
ft_split.c\
operation_swap.c\
operation_push.c\
operation_rotate.c\
operation_reverse_rotate.c\
sort.c\
parsing.c\
sort_less_than_five.c)

OBJ = $(SRC:.c=.o)

SRC_BN = $(addprefix ./bonus/, checker_bonus.c\
get_next_line.c\
get_next_line_utils.c\
operation_push_bonus.c\
operation_swap_bonus.c\
operation_rotate_bonus.c\
operation_reverse_rotate_bonus.c\
stack.c\
push_swap_utils.c\
ft_split.c\
sort.c)

OBJ_BN = $(SRC_BN:.c=.o)

all : $(NAME)

bonus : $(BONUS)

$(NAME) : $(OBJ)
	$(CC) $(CFLAG) -o $@ $^

$(BONUS) : $(OBJ_BN)
	$(CC) $(CFLAG) -o $@ $^

clean :
	$(RM) $(OBJ) $(OBJ_BN)

fclean : clean
	$(RM) $(NAME) $(BONUS)

re : fclean all

.PHONY : all clean fclean re bonus