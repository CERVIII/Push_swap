/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritm_100_500.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:10:12 by pcervill          #+#    #+#             */
/*   Updated: 2023/03/01 17:55:05 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	chunkslen(t_stacks *data)
{
	if (data->count_a >= 100 && data->count_a < 500)
		data->chunks = 20;
	else if (data->count_a >= 500)
		data->chunks = 50;
	else
		data->chunks = 5;
}

void	push_min(t_list **stack_a, t_list **stack_b, t_stacks *data, int i)
{
	int	size;
	int	block;
	int	lastnum;

	block = 0;
	lastnum = data->cpy[i];
	ft_pb(stack_a, stack_b, data);
	size = data->count_a + data->count_b;
	if (size >= 500)
		block = 25;
	else if (size >= 100 && size < 500)
		block = 10;
	else if (size > 5)
		block = 3;
	if (data->count_b >= 2 && (*stack_b)->content < data->cpy[i - block]
		&& data->count_a >= 2 && (*stack_a)->content > lastnum)
		ft_rr(stack_a, stack_b, data);
	if (data->count_b >= 2 && (*stack_b)->content < data->cpy[i - block])
		ft_rb(stack_b, data);
}

void	rotate_max(t_list **stack_a, t_list **stack_b, t_stacks *data, int i)
{
	int	size;
	int	block;

	block = 0;
	size = data->count_a + data->count_b;
	if (size >= 500)
		block = 25;
	else if (size >= 100 && size < 500)
		block = 10;
	else if (size > 5)
		block = 3;
	if (data->count_b >= 2 && (*stack_b)->content < data->cpy[i - block])
		ft_rr(stack_a, stack_b, data);
	else
		ft_ra(stack_a, data);
}

void	push_to_b(t_list **stack_a, t_list **stack_b, t_stacks *data)
{
	int	i;
	int	size;
	int	lastnum;

	i = data->chunks;
	size = data->count_a + data->count_b;
	lastnum = data->cpy[i];
	while (data->count_a > 0)
	{
		while (data->count_b < i)
		{
			if (lastnum > (*stack_a)->content || i == size)
				push_min(stack_a, stack_b, data, i);
			else
				rotate_max(stack_a, stack_b, data, i);
		}
		i = i + data->chunks;
		if (i < size)
			lastnum = data->cpy[i];
		else
		{
			lastnum = data->cpy[size - 1];
			i = size;
		}
	}
}

void	al_hundred(t_list **stack_a, t_list **stack_b, t_stacks *data)
{
	array_sort(*stack_a, data, 'a');
	chunkslen(data);
	push_to_b(stack_a, stack_b, data);
	free(data->cpy);
	push_to_a(stack_a, stack_b, data);
}
