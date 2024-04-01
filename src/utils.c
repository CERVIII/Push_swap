/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:10:35 by pcervill          #+#    #+#             */
/*   Updated: 2024/04/01 15:15:22 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
	Funcion para limpiar la lista.
		1º) Creo una copia de la lista.
		2º) Recorro la lista y libero la memoria de cada nodo.
		3º) Igualo la lista a NULL.
*/
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

/*
	Funcion para comprobar si es mas optimo hacer un sa/sb o un ss.
		1º) Compruebo si el stack A tiene mas de 2 elementos y si el primer
			elemento es mayor que el segundo.
			Compruebo si el stack B tiene mas de 2 elementos y si el primer
			elemento es mayor que el segundo.
		2º) Si se cumplen las dos condiciones, hago un ss.
		3º) Si solo se cumple la primera, hago un sa.
		4º) Si solo se cumple la segunda, hago un sb.
*/
void	ft_ss_sx(t_list **stack_a, t_list **stack_b, t_stacks *data)
{
	if (data->count_a >= 2 && (*stack_a)->content > (*stack_a)->next->content
		&& data->count_b >= 2
		&& (*stack_a)->content > (*stack_a)->next->content)
		ft_ss(stack_a, stack_b, data);
	else if (data->count_a >= 2
		&& (*stack_a)->content > (*stack_a)->next->content)
			ft_sa(stack_a, data);
}
