/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:10:35 by pcervill          #+#    #+#             */
/*   Updated: 2023/01/25 17:14:52 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	stackclear(t_list **stack_a)
{
	t_list	*cpy;

	if (!stack_a)
		return ;
	cpy = *stack_a;
	while (cpy)
	{
		cpy = (*stack_a)->next;
		free(*stack_a);
		*stack_a = cpy;
	}
	stack_a = NULL;
	return ;
}

void	ft_lstorder(t_list **stack_a)
{
	t_list	*cpy;
	t_list	*cpy2;

	cpy = *stack_a;
	cpy2 = cpy->next;
	while (cpy->next != NULL)
	{
		if (cpy->content > cpy2->content)
			return ;
		cpy = cpy->next;
		cpy2 = cpy2->next;
	}
	exit (0);
}

void	ft_lst_inverted(t_list **stack_a, t_stacks *data)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *stack_a;
	tmp2 = tmp->next;
	while (tmp2 != NULL)
	{
		if (tmp->content < tmp2->content)
			return ;
		tmp = tmp->next;
		tmp2 = tmp2->next;
	}
	ft_sa(stack_a, data);
	return ;
}

void	maxminstack(t_list *stack_a, t_stacks *data)
{
	data->max = -2147483648;
	data->min = 2147483647;
	while (stack_a)
	{
		if (stack_a->content > data->max)
			data->max = stack_a->content;
		if (stack_a->content < data->min)
			data->min = stack_a->content;
		stack_a = stack_a->next;
	}
	posmaxmin(stack_a, data);
}

void	posmaxmin(t_list *stack_a, t_stacks *data)
{
	int	statemax;
	int	statemin;

	statemax = 0;
	statemin = 0;
	while (stack_a)
	{
		if (stack_a->content == data->max)
			statemax++;
		if (stack_a->content == data->min)
			statemin++;
		if (statemax != 1)
			data->posmax++;
		if (statemin != 1)
			data->posmin++;
			stack_a = stack_a->next;
	}
}

int	ft_only_spaces(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
			|| str[i] == ' ' || str[i] == '\r' || str[i] == '\f')
			return (1);
		else if (str[i] == '-')
			return (1);
	}
	return (0);
}

void	ra_rra(t_list **stack_a, t_stacks *data)
{
	if (data->posmax < (data->count_a / 2)
		|| data->posmin < (data->count_a / 2))
		ft_ra(stack_a, data);
	else
		ft_rra(stack_a, data);
}
