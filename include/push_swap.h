/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 10:56:06 by pcervill          #+#    #+#             */
/*   Updated: 2023/02/27 16:44:49 by pcervill         ###   ########.fr       */
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

typedef struct s_stacks
{
	int		count_a;
	int		count_b;
	int		min;
	int		max;
	int		num;
	int		movs;
	int		posmax;
	int		posmin;
	int		*cpy;
	int		chunks;
}	t_stacks;

/*	 	PUSH_SWAP.C		*/
void	initdata(t_stacks *data);
void	ft_printst(t_list *stack_a, t_list *stack_b);
void	select_al(t_list **stack_a, t_list **stack_b, t_stacks *data);
void	example_movs(t_list **stack_a, t_list **stack_b, t_stacks *data);

/* 		ARGUMENTS.C 	*/
void	argcheck(char *argv[], t_stacks *data, t_list **stack_a);
int		checkparams(char *argv);
void	ft_write_lst(t_list **stack_a, int num);
void	ft_isrepeat(t_list *stack_a, int num);
void	ft_freestring(char **str);

/* 		FT_STACK.C		*/
void	ft_lstorder(t_list **stack_a);
void	ft_lst_inverted(t_list **stack_a, t_stacks *data);
void	maxminstack(t_list **stack_a, t_stacks *data);
void	stackclear(t_list **stack_a);
int		ft_only_spaces(const char *str);
void	posmaxmin(t_list *stack_a, t_stacks *data);
void	ra_rra(t_list **stack_a, t_stacks *data, int pos);

/* 		MOVS1.C			*/
void	ft_sa(t_list **stack_a, t_stacks *data);
void	ft_sb(t_list **stack_b, t_stacks *data);
void	ft_ss(t_list **stack_a, t_list **stack_b, t_stacks *data);
void	ft_pa(t_list **stack_a, t_list **stack_b, t_stacks *data);
void	ft_pb(t_list **stack_a, t_list **stack_b, t_stacks *data);

/* 		MOVS2.C			 */
void	ft_ra(t_list **stack_a, t_stacks *data);
void	ft_rb(t_list **stack_b, t_stacks *data);
void	ft_rr(t_list **stack_a, t_list **stack_b, t_stacks *data);

/* 		MOVS3.C			 */
void	ft_rra(t_list **stack_a, t_stacks *data);
void	ft_rrb(t_list **stack_b, t_stacks *data);
void	ft_rrr(t_list **stack_a, t_list **stack_b, t_stacks *data);
void	auxrrb(t_list **stack_b);

/* 		ALGORITM3_5		 */
void	al_two(t_list **stack_a, t_stacks *data);
void	al_three(t_list **stack_a, t_stacks *data);
void	al_five(t_list **stack_a, t_list **stack_b, t_stacks *data);
void	ft_move_a(t_list **stack_a, t_list **stack_b, t_stacks *data);

/* 		ALGORITM100.C */
void	push_min(t_list **stack_a, t_list **stack_b, t_stacks *data, int i);
void	rotate_max(t_list **stack_a, t_list **stack_b, t_stacks *data, int i);
void	al_hundred(t_list **stack_a, t_list **stack_b, t_stacks *data);
void	cpyarray(t_list *stack_a, t_stacks *data);
void	sort_array(t_stacks *data);
void	chunkslen(t_stacks *data);

/* 		ALGORITM500.C */
void	al_fivehundred(t_list **stack_a, t_list **stack_b, t_stacks *data);

#endif