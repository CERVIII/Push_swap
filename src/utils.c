/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:10:35 by pcervill          #+#    #+#             */
/*   Updated: 2024/03/19 13:44:49 by pcervill         ###   ########.fr       */
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

/*
	Funcion para comprobar si la lista esta ordenada.
		1º) Creo dos nodos para recorrer la lista.
		2º) Comparo el contenido de cada nodo con el siguiente.
		3º) Si el contenido del primer nodo es mayor que el del segundo,
			la lista no esta ordenada.
		4º) Si la lista esta ordenada, salgo del programa.
*/
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

void	ft_ss_sx(t_list **stack_a, t_list **stack_b, t_stacks *data, char mod)
{
	if (data->count_a >= 2 && (*stack_a)->content
		> (*stack_a)->next->content && data->count_b >= 2
		&& (*stack_a)->content > (*stack_a)->next->content)
		ft_ss(stack_a, stack_b, data);
	if (data->count_a >= 2 && (*stack_a)->content
		> (*stack_a)->next->content)
	{
		if (mod == 'a')
			ft_sa(stack_a, data);
		if (mod == 'b')
			ft_sb(stack_b, data);
	}
	return ;
}
