/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_maxmin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 12:27:31 by pcervill          #+#    #+#             */
/*   Updated: 2023/03/01 10:49:03 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	minstack(t_list *stack, t_stacks *data, char mod)
{
	data->min_a = 2147483647;
	data->min_b = 2147483647;
	if (mod == 'a')
	{
		while (stack != NULL)
		{
			if (stack->content < data->min_a)
				data->min_a = stack->content;
			stack = stack->next;
		}
	}
	else if (mod == 'b')
	{
		while (stack != NULL)
		{
			if (stack->content < data->min_b)
				data->min_b = stack->content;
			stack = stack->next;
		}
	}
}

void	maxstack(t_list *stack, t_stacks *data, char mod)
{
	data->max_a = -2147483648;
	data->max_b = -2147483648;
	if (mod == 'a')
	{
		while (stack != NULL)
		{
			if (stack->content > data->max_a)
				data->max_a = stack->content;
			stack = stack->next;
		}
	}
	else if (mod == 'b')
	{
		while (stack != NULL)
		{
			if (stack->content > data->max_b)
				data->max_b = stack->content;
			stack = stack->next;
		}
	}
}

void	maxminstack(t_list *stack_a, t_stacks *data, char mod)
{
	maxstack(stack_a, data, mod);
	minstack(stack_a, data, mod);
}
