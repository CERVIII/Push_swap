/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_posmaxmin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 12:29:15 by pcervill          #+#    #+#             */
/*   Updated: 2023/03/01 10:49:10 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	posmax(t_list *stack, t_stacks *data, char mod)
{
	data->posmax_a = 0;
	data->posmax_b = 0;
	maxstack(stack, data, mod);
	if (mod == 'a' && data->count_a != 0)
	{
		while (stack->content != data->max_a)
		{
			if (stack->content != data->max_a)
				data->posmax_a++;
			stack = stack->next;
		}
	}
	else if (mod == 'b' && data->count_b != 0)
	{
		while (stack->content != data->max_b)
		{
			data->posmax_b++;
			stack = stack->next;
		}
	}
	return ;
}

void	posmin(t_list *stack, t_stacks *data, char mod)
{
	data->posmin_a = 0;
	data->posmin_b = 0;
	minstack(stack, data, mod);
	if (mod == 'a' && data->count_a != 0)
	{
		while (stack->content != data->min_a)
		{
			data->posmin_a++;
			stack = stack->next;
		}
	}
	else if (mod == 'b' && data->count_b != 0)
	{
		while (stack->content != data->min_b)
		{
			data->posmin_b++;
			stack = stack->next;
		}
	}
	return ;
}

void	posmaxmin(t_list *stack, t_stacks *data, char mod)
{
	posmax(stack, data, mod);
	posmin(stack, data, mod);
	return ;
}
