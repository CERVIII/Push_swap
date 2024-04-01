/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movs2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:21:18 by pcervill          #+#    #+#             */
/*   Updated: 2024/04/01 11:56:30 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
	Funcion para hacer un rotate en el stack A, el primer elemento pasa
	a ser el ultimo.
		1º) Creo dos variables para almacenar el primer y ultimo nodo.
		2º) Cambio los nodos de posicion.
		3º) Imprimo el movimiento.
*/
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

/*
	Funcion para hacer un rotate en el stack B, el primer elemento pasa
	a ser el ultimo.
		1º) Creo dos variables para almacenar el primer y ultimo nodo.
		2º) Cambio los nodos de posicion.
		3º) Imprimo el movimiento.
*/
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

/*
	Funcion para hacer un rotate en los stacks A y B, el primer elemento pasa
	a ser el ultimo.
		1º) Creo dos variables para almacenar el primer y ultimo nodo.
		2º) Cambio los nodos de posicion.
		3º) Imprimo el movimiento.
*/
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
