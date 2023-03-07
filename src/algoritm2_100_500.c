/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritm2_100_500.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:32:40 by pcervill          #+#    #+#             */
/*   Updated: 2023/03/06 12:03:51 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_iterative(int hold, int count)
{
	if (hold <= (count / 2))
		return (hold - 1);
	else
		return (count - hold + 1);
}

void	select_iter(t_list **stack_a, t_list **stack_b, t_stacks *data)
{
	while (data->posmax_b > 0)
	{
		if (data->count_b > 1)
		{
			if (data->count_b >= 2 && (*stack_b)->content
				== data->cpy[data->count_b - 2] && data->flag == 0)
			{
				ft_pa(stack_a, stack_b, data);
				data->posmax_b = 0;
				data->flag = 1;
			}
			else if (data->hold > (data->count_b / 2))
				ft_rrb(stack_b, data);
			else
				ft_rb(stack_b, data);
		}
		data->posmax_b--;
	}
	if (data->posmax_b == 0)
	{
		ft_pa(stack_a, stack_b, data);
		data->flag = 0;
	}
	free(data->cpy);
}

void	push_to_a(t_list **stack_a, t_list **stack_b, t_stacks *data)
{
	while (*stack_b)
	{
		posmaxmin(*stack_b, data, 'b');
		data->hold = data->posmax_b + 1;
		data->posmax_b = get_iterative(data->hold, data->count_b);
		array_sort(*stack_b, data, 'b');
		select_iter(stack_a, stack_b, data);
		ft_ss_sx(stack_a, stack_b, data, 'a');
	}
}
