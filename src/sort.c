/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:12:09 by pcervill          #+#    #+#             */
/*   Updated: 2023/03/01 17:03:42 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort(t_stacks *data, int size)
{
	int	i;
	int	pos;
	int	min;
	int	aux;

	i = 0;
	while (i < size)
	{
		min = i;
		pos = i + 1;
		while (pos < size)
		{
			if (data->cpy[pos] < data->cpy[min])
				min = pos;
			pos++;
		}
		aux = data->cpy[i];
		data->cpy[i] = data->cpy[min];
		data->cpy[min] = aux;
		i++;
	}
}

void	array_sort(t_list *stack, t_stacks *data, char mod)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	if (mod == 'a')
		size = data->count_a;
	else if (mod == 'b')
		size = data->count_b;
	data->cpy = (int *) malloc(size * sizeof(int));
	if (!data->cpy)
		return ;
	while (stack)
	{
		data->cpy[i] = stack->content;
		stack = stack->next;
		i++;
	}
	sort(data, size);
}
