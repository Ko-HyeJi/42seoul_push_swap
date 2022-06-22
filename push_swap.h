/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyko <hyko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 17:58:35 by hyko              #+#    #+#             */
/*   Updated: 2022/06/22 16:49:06 by hyko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>

typedef struct s_list
{
	int				index;
	int				value;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

typedef	struct s_stack
{
	t_list	*head;
	t_list	*curr;
}	t_stack;


size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
static char	**ft_malloc_error(char **str);
int	word_count(char const *s, char c);
int	word_len(char const *s, char c);
char	**ft_split(char const *s, char c);
long long	ft_atol(const char *str);

#endif