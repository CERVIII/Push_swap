/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritm100.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:10:12 by pcervill          #+#    #+#             */
/*   Updated: 2023/02/14 12:46:22 by pcervill         ###   ########.fr       */
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
	int	i;

	i = 0;
	stack_b = NULL;
	cpyarray(stack_a, data);
	while (data->cpy[i])
	{
		printf("%d\n", data->cpy[i++]);
	}
	free(data->cpy);
	return ;
}

void	cpyarray(t_list **stack_a, t_stacks *data)
{
	t_list	*tmp;
	int		i;

	i = 0;
	data->cpy = (int *) calloc(sizeof(int), (data->count_a));
	tmp = *stack_a;
	while (tmp != NULL)
	{
		data->cpy[i++] = tmp->content;
		tmp = tmp->next;
	}
}
