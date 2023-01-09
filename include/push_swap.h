/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 10:56:06 by pcervill          #+#    #+#             */
/*   Updated: 2023/01/09 16:31:43 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <ctype.h>
# include <unistd.h>
# include <sys/types.h>
# include <stdio.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>

# define NORMAL "\x1B[0m"
# define RED "\x1B[31m"
# define GREEN "\x1B[32m"
# define YELLOW "\x1B[33m"
# define BLUE "\x1B[34m"
# define MAGENT "\x1B[35m"
# define CYAN "\x1B[36m"
# define WHITE "\x1B[37m"

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
}	t_stack;

typedef struct s_stacks
{
	int		count_a;
	int		count_b;
	int		min;
	int		max;
	int		num;
	t_stack	*a;
	t_stack	*b;
}	t_stacks;

int		ft_error(char *error);
void	argcheck(char *argv[], t_stacks *data, t_list **stack_a);
void	ft_write_lst(t_list **stack_a, int num);
int		checkparams(char *argv);
int		ft_countword(char *str, char c);
int		ft_countspace(char *str, char c);

int		*strnumber(int argc, char **argv);
void	ft_freestring(char **str);

int		stacksize(t_stack *stack);
void	maxminstack(t_stacks *data);
t_stack	*stackadd(t_stack *stack, int number);
t_stack	*stacknew(int content);
t_stack	*stacklast(t_stack *stack);
void	stackaddback(t_stack *stack, int content);
t_stack	*stackclear(t_stack *stack_a);

#endif