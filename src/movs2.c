/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movs2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:21:18 by pcervill          #+#    #+#             */
/*   Updated: 2023/01/23 16:29:30 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_ra(t_list **stack_a, t_stacks *data)
{
	t_list	*first;
	t_list	*last;

	if (!stack_a)
		return ;
	first = *stack_a;
	last = *stack_a;
	while (last->next)
		last = last->next;
	*stack_a = first->next;
	first->next = NULL;
	last->next = first;
	ft_putstr_fd("ra\n", 1);
	data->movs++;
	return ;
}

void	ft_rb(t_list **stack_b, t_stacks *data)
{
	t_list	*first;
	t_list	*last;

	if (!stack_b)
		return ;
	first = *stack_b;
	last = *stack_b;
	while (last->next)
		last = last->next;
	*stack_b = first->next;
	first->next = NULL;
	last->next = first;
	ft_putstr_fd("rb\n", 1);
	data->movs++;
	return ;
}

void	ft_rr(t_list **stack_a, t_list **stack_b, t_stacks *data)
{
	t_list	*first;
	t_list	*last;

	if (!stack_a || !stack_b)
		return ;
	first = *stack_a;
	last = *stack_a;
	while (last->next)
		last = last->next;
	*stack_a = first->next;
	first->next = NULL;
	last->next = first;
	first = NULL;
	last = NULL;
	first = *stack_b;
	last = *stack_b;
	while (last->next)
		last = last->next;
	*stack_b = first->next;
	first->next = NULL;
	last->next = first;
	ft_putstr_fd("rr\n", 1);
	data->movs++;
	return ;
}
