# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyko <hyko@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/23 19:49:42 by hyko              #+#    #+#              #
#    Updated: 2022/06/30 20:05:29 by hyko             ###   ########.fr        #
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
get_next_line_bonus.c\
get_next_line_utils_bonus.c\
operation_push_bonus.c\
operation_swap_bonus.c\
operation_rotate_bonus.c\
operation_reverse_rotate_bonus.c\
stack_bonus.c\
push_swap_utils_bonus.c\
ft_split_bonus.c\
sort_bonus.c\
parsing_bonus.c)

OBJ_BN = $(SRC_BN:.c=.o)

$(NAME) : $(OBJ)
	$(CC) $(CFLAG) -o $@ $^

$(BONUS) : $(OBJ_BN)
	$(CC) $(CFLAG) -o $@ $^
	
all : $(NAME)

bonus : $(BONUS)

clean :
	$(RM) $(OBJ) $(OBJ_BN)

fclean : clean
	$(RM) $(NAME) $(BONUS)

re : fclean all

.PHONY : all clean fclean re bonus