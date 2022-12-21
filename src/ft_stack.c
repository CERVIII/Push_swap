/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:10:35 by pcervill          #+#    #+#             */
/*   Updated: 2022/12/21 15:15:39 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*stackadd(t_stack *stack, int number)
{
	t_stack	*new;
	t_stack	*aux;

	new = (t_stack *) malloc(sizeof(t_stack));
	aux = (t_stack *) malloc(sizeof(t_stack));
	new->content = number;
	new->next = NULL;
	if (stack == NULL)
	{
		stack = new;
	}
	else
	{
		aux = stack;
		while (aux->next)
			aux = aux->next;
		aux->next = new;
	}
	return (stack);
}

t_stack	*ft_stackclear(t_stack *stack_a)
{
	t_stack	*cpy;
	t_stack	*aux;

	cpy = stack_a;
	while (cpy)
	{
		aux = cpy->next;
		free(cpy);
		cpy = aux;
	}
	stack_a = NULL;
	return (stack_a);
}











int	stacksize(t_stack *stack)
{
	int	cont;

	cont = 0;
	while (stack)
	{
		cont++;
		stack = stack->next;
	}
	return (cont);
}

void	maxminstack(t_stacks *data, t_stack *stack)
{
	while (data->a)
	{
		if (stack->content > data->max)
			data->max = stack->content;
		if (stack->content < data->min)
			data->min = stack->content;
		stack = stack->next;
	}
}
