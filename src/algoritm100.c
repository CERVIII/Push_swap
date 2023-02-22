/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritm100.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:10:12 by pcervill          #+#    #+#             */
/*   Updated: 2023/02/22 15:05:04 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	al_hundred(t_list **stack_a, t_list **stack_b, t_stacks *data)
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

/* void	al_hundred(t_list **stack_a, t_stacks *data)
{
	convertpos(stack_a, data);
}

void	convertpos(t_list **stack_a, t_stacks *data)
{
	int		num;
	int		conv;
	int		j;
	t_list	*tmp;
	t_list	*tmp2;

	data->cpy = (int *)calloc(sizeof(int), data->count_a);
	tmp = *stack_a;
	j = 0;
	while (tmp != NULL)
	{
		conv = 0;
		num = tmp->content;
		tmp2 = *stack_a;
		while (tmp2 != NULL)
		{
			if (num > tmp2->content)
				conv++;
			tmp2 = tmp2->next;
		}
		data->cpy[j] = conv;
		printf("%d		%d\n", tmp->content, data->cpy[j++]);
		tmp = tmp->next;
	}
}

void	chunks(t_stacks *data, int chunks)
{
	int	numchunk;

	numchunk = data->count_a / chunks;
} */
