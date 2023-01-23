/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritm3_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 10:15:37 by pcervill          #+#    #+#             */
/*   Updated: 2023/01/23 12:45:49 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	al_three(t_list **stack_a)
{
	int		a;
	int		b;
	int		c;
	t_list	*tmp;

	tmp = NULL;
	a = 0;
	b = 0;
	c = 0;
	while (!(a < b && b < c && c > a))
	{
		tmp = *stack_a;
		a = tmp->content;
		tmp = tmp->next;
		b = tmp->content;
		tmp = tmp->next;
		c = tmp->content;
		if ((a > b && a < c && b < c) || (a > c && b > c && a > b)
			|| (a < b && a < c && b > c))
			ft_sa(stack_a);
		if (a > b && a > c && b < c)
			ft_ra(stack_a);
		if (a < b && a > c && b > c)
			ft_rra(stack_a);
	}
}

void	al_five(t_list **stack_a, t_list **stack_b)
{
	int		i;
	int		a;
	int		b;
	t_list	*tmp;

	i = 2;
	while (i != 0)
	{
		ft_pb(stack_a, stack_b);
		i--;
	}
	al_three(stack_a);
	tmp = *stack_a;
	a = tmp->content;
	tmp = tmp->next;
	b = tmp->content;
}
