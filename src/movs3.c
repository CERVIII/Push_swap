/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movs3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:51:16 by pcervill          #+#    #+#             */
/*   Updated: 2024/04/04 10:46:33 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_rra(t_list **stack_a, t_stacks *data)
{
	t_list	*last;
	t_list	*tmp;

	last = *stack_a;
	tmp = *stack_a;
	while (last->next)
	{
		tmp = last;
		last = last->next;
	}
	last->next = *stack_a;
	*stack_a = last;
	tmp->next = NULL;
	ft_putstr_fd("rra\n", 1);
	data->movs++;
	return ;
}

void	ft_rrb(t_list **stack_b, t_stacks *data)
{
	t_list	*last;
	t_list	*tmp;

	last = *stack_b;
	tmp = *stack_b;
	while (last->next)
	{
		tmp = last;
		last = last->next;
	}
	last->next = *stack_b;
	*stack_b = last;
	tmp->next = NULL;
	ft_putstr_fd("rrb\n", 1);
	data->movs++;
	return ;
}

void	auxrrb(t_list **stack_b)
{
	t_list	*last;
	t_list	*tmp;

	last = *stack_b;
	tmp = *stack_b;
	while (last->next)
	{
		tmp = last;
		last = last->next;
	}
	last->next = *stack_b;
	*stack_b = last;
	tmp->next = NULL;
}

void	ft_rrr(t_list **stack_a, t_list **stack_b, t_stacks *data)
{
	t_list	*last;
	t_list	*tmp;

	last = *stack_a;
	tmp = *stack_a;
	while (last->next)
	{
		tmp = last;
		last = last->next;
	}
	last->next = *stack_a;
	*stack_a = last;
	tmp->next = NULL;
	auxrrb(stack_b);
	ft_putstr_fd("rrr\n", 1);
	data->movs++;
	return ;
}
