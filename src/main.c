/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 12:05:05 by pcervill          #+#    #+#             */
/*   Updated: 2024/04/04 10:48:12 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* static void	leaks(void)
{
	system("leaks -q push_swap");
} */
// atexit(leaks);

void	initdata(t_stacks *data)
{
	data->count_a = 0;
	data->min_a = 0;
	data->max_a = 0;
	data->posmax_a = 0;
	data->posmin_a = 0;
	data->count_b = 0;
	data->min_b = 0;
	data->max_b = 0;
	data->posmax_b = 0;
	data->posmin_b = 0;
	data->movs = 0;
	data->hold = 0;
	data->chunks = 0;
	data->flag = 0;
}

void	select_al(t_list **stack_a, t_list **stack_b, t_stacks *data)
{
	data->count_a = ft_lstsize(*stack_a);
	data->count_b = ft_lstsize(*stack_b);
	maxminstack(*stack_a, data, 'a');
	posmaxmin(*stack_a, data, 'a');
	if (data->count_a <= 2)
	{
		al_two(stack_a, data);
		return ;
	}
	if (data->count_a <= 3)
	{
		al_three(stack_a, data);
		return ;
	}
	else if (data->count_a <= 5)
	{
		al_five(stack_a, stack_b, data);
		return ;
	}
	else if (data->count_a > 5)
	{
		al_hundred(stack_a, stack_b, data);
		return ;
	}
	free(stack_b);
}

int	main(int argc, char *argv[])
{
	t_stacks	*data;
	t_list		*stack_a;
	t_list		*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	data = (t_stacks *) malloc(sizeof(t_stacks));
	initdata(data);
	if (!data || argc < 2)
		exit (1);
	argcheck(argv, &stack_a);
	select_al(&stack_a, &stack_b, data);
	stackclear(&stack_a);
	free(data);
	return (0);
}
