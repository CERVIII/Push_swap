/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritm100.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:10:12 by pcervill          #+#    #+#             */
/*   Updated: 2023/02/13 17:59:20 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* void	al_hundred(t_list **stack_a, t_list **stack_b, t_stacks *data)
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
} */

void	al_hundred(t_list **stack_a, t_list **stack_b, t_stacks *data)
{
	t_list	*tmp;
	int		*cpy;

	cpy = (int *) malloc(sizeof(data->count_a));
	tmp = *stack_a;
	while (tmp != NULL)
	{
		cpy = tmp->content;
		tmp = tmp->next;
	}
}

int	*ordercpy(int *cpy)
{
	int	swp;
	int	swp2;

	while ()
	{
		/* swp = stack_a;
		swp2 = swp->next;
		stack_a = swp2;
		swp->next = swp2->next;
		swp2->next = swp; */
	}
}
