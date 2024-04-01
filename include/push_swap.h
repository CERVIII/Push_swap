/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 10:56:06 by pcervill          #+#    #+#             */
/*   Updated: 2024/04/01 15:16:59 by pcervill         ###   ########.fr       */
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
	int		min_a;
	int		min_b;
	int		max_a;
	int		max_b;
	int		posmax_a;
	int		posmax_b;
	int		posmin_a;
	int		posmin_b;
	int		movs;
	int		*cpy;
	int		lastnum;		//cambio temporal
	int		chunks;
	int		hold;
	int		flag;
}	t_stacks;

/*	 	PUSH_SWAP.C		*/
void	initdata(t_stacks *data);
void	select_al(t_list **stack_a, t_list **stack_b, t_stacks *data);

/* 		ARGUMENTS.C 	*/
int		checkparams(char *argv);
void	ft_write_lst(t_list **stack_a, int num);
void	ft_isrepeat(t_list *stack_a, int num);
void	argcheck(char *argv[], t_list **stack_a);

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

/* 		ALGORITM2_3_5		 */
void	ra_rra(t_list **stack_a, t_stacks *data, int pos);
void	al_two(t_list **stack_a, t_stacks *data);
void	al_three(t_list **stack_a, t_stacks *data);
void	al_five(t_list **stack_a, t_list **stack_b, t_stacks *data);
void	ft_move_a(t_list **stack_a, t_list **stack_b, t_stacks *data);

/* 		ALGORITM100-500.C */
void	chunkslen(t_stacks *data);
void	push_min(t_list **stack_a, t_list **stack_b, t_stacks *data, int i);
void	rotate_max(t_list **stack_a, t_list **stack_b, t_stacks *data, int i);
void	push_to_b(t_list **stack_a, t_list **stack_b, t_stacks *data);
void	al_hundred(t_list **stack_a, t_list **stack_b, t_stacks *data);

/* 		ALGORITM2_100_500.C */
void	select_iter(t_list **stack_a, t_list **stack_b, t_stacks *data);
int		get_iterative(int hold, int count);
void	push_to_a(t_list **stack_a, t_list **stack_b, t_stacks *data);

/* 		SORT.C			 */
void	sort(t_stacks *data, int size);
void	array_sort(t_list *stack_a, t_stacks *data, char mod);

/* 		UTILS.C		*/
void	stackclear(t_list **stack_a);
void	ft_lstorder(t_list **stack_a);
void	ft_ss_sx(t_list **stack_a, t_list **stack_b, t_stacks *data);

/* 		UTILS_MAXMIN.C */
void	minstack(t_list *stack, t_stacks *data, char mod);
void	maxstack(t_list *stack, t_stacks *data, char mod);
void	maxminstack(t_list *stack, t_stacks *data, char mod);

/* 		UTILS_POSMAXMIN.C */
void	posmax(t_list *stack, t_stacks *data, char mod);
void	posmin(t_list *stack, t_stacks *data, char mod);
void	posmaxmin(t_list *stack, t_stacks *data, char mod);

#endif