/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movs1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:22:32 by pcervill          #+#    #+#             */
/*   Updated: 2023/01/23 16:26:47 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_sa(t_list **stack_a, t_stacks *data)
{
	t_list	*swap;
	t_list	*swap2;

	swap = *stack_a;
	swap2 = swap->next;
	*stack_a = swap2;
	swap->next = swap2->next;
	swap2->next = swap;
	ft_putstr_fd("sa\n", 1);
	data->movs++;
	return ;
}

void	ft_sb(t_list **stack_b, t_stacks *data)
{
	t_list	*swap;
	t_list	*swap2;

	swap = *stack_b;
	swap2 = swap->next;
	*stack_b = swap2;
	swap->next = swap2->next;
	swap2->next = swap;
	ft_putstr_fd("sb\n", 1);
	data->movs++;
	return ;
}

void	ft_ss(t_list **stack_a, t_list **stack_b, t_stacks *data)
{
	t_list	*swap;
	t_list	*swap2;

	swap = *stack_a;
	swap2 = swap->next;
	*stack_a = swap2;
	swap->next = swap2->next;
	swap2->next = swap;
	swap = NULL;
	swap2 = NULL;
	swap = *stack_b;
	swap2 = swap->next;
	*stack_b = swap2;
	swap->next = swap2->next;
	swap2->next = swap;
	ft_putstr_fd("ss\n", 1);
	data->movs++;
	return ;
}

void	ft_pa(t_list **stack_a, t_list **stack_b, t_stacks *data)
{
	t_list	*tmp;

	if (*stack_b == NULL)
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = *stack_a;
	*stack_a = tmp;
	ft_putstr_fd("pa\n", 1);
	data->count_a++;
	data->count_b--;
	data->movs++;
	return ;
}

void	ft_pb(t_list **stack_a, t_list **stack_b, t_stacks *data)
{
	t_list	*tmp;

	if (stack_a == NULL)
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = *stack_b;
	*stack_b = tmp;
	ft_putstr_fd("pb\n", 1);
	data->count_a--;
	data->count_b++;
	data->movs++;
	return ;
}
