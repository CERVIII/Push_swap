/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritm500.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:58:53 by pcervill          #+#    #+#             */
/*   Updated: 2023/02/22 14:59:29 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	al_fivehundred(t_list **stack_a, t_list **stack_b, t_stacks *data)
{
	t_list	*tmp;

	tmp = *stack_a;
	while (data->count_a != 0)
	{
		tmp = *stack_a;
		posmaxmin(*stack_a, data);
		if (tmp->content != data->min)
			ra_rra(stack_a, data, data->posmin);
		if (tmp->content == data->min)
		{
			ft_pb(stack_a, stack_b, data);
			maxminstack(stack_a, data);
		}
	}
	while (data->count_b != 0)
	{
		ft_pa(stack_a, stack_b, data);
	}
	return ;
}