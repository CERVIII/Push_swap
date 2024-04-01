/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movs3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:51:16 by pcervill          #+#    #+#             */
/*   Updated: 2024/04/01 11:57:57 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
	Funcion para hacer un reverse rotate en el stack A, el ultimo elemento pasa
	a ser el primero.
		1º) Creo dos variables para almacenar el primer y ultimo nodo.
		2º) Cambio los nodos de posicion.
		3º) Imprimo el movimiento.
*/
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

/*
	Funcion para hacer un reverse rotate en el stack B, el ultimo elemento pasa
	a ser el primero.
		1º) Creo dos variables para almacenar el primer y ultimo nodo.
		2º) Cambio los nodos de posicion.
		3º) Imprimo el movimiento.
*/
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

/*
	Funcion auxiliar para hacer un reverse rotate en el stack B, el ultimo elemento pasa
	a ser el primero.
		1º) Creo dos variables para almacenar el primer y ultimo nodo.
		2º) Cambio los nodos de posicion.
*/
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

/*
	Funcion para hacer un reverse rotate en los stacks A y B, el ultimo elemento pasa
	a ser el primero.
		1º) Creo dos variables para almacenar el primer y ultimo nodo.
		2º) Cambio los nodos de posicion.
		3º) Imprimo el movimiento.
*/
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
