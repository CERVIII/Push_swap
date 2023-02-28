/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:12:09 by pcervill          #+#    #+#             */
/*   Updated: 2023/02/28 11:12:48 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	cpyarray(t_list *stack_a, t_stacks *data)
{
	int	i;

	i = 0;
	data->cpy = (int *) malloc(data->count_a * sizeof(int));
	if (!data->cpy)
		return ;
	while (stack_a)
	{
		data->cpy[i] = stack_a->content;
		stack_a = stack_a->next;
		i++;
	}
}

void	sort_array(t_stacks *data)
{
	int	i;
	int	pos;
	int	min;
	int	aux;

	i = 0;
	while (i < data->count_a)
	{
		min = i;
		pos = i + 1;
		while (pos < data->count_a)
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