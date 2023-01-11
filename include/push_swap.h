/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 10:56:06 by pcervill          #+#    #+#             */
/*   Updated: 2023/01/11 17:52:05 by pcervill         ###   ########.fr       */
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
}	t_stacks;

/*	 	PUSH_SWAP.C		*/
void	initdata(t_stacks *data);
void	ft_printst(t_list *stack);

/* 		ARGUMENTS.C 	*/
void	argcheck(char *argv[], t_stacks *data, t_list **stack_a);
int		checkparams(char *argv);
void	ft_write_lst(t_list **stack_a, int num);
void	ft_isrepeat(t_list *stack_a, int num);
void	ft_freestring(char **str);

/* 		FT_STACK.C		*/
void	ft_lstorder(t_list **stack_a);
void	maxminstack(t_list *stack_a, t_stacks *data);
void	stackclear(t_list **stack_a);

/* 		MOVS1.C			*/
void	ft_sa(t_list **stack_a);
#endif