/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_maxmin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 12:27:31 by pcervill          #+#    #+#             */
/*   Updated: 2024/03/19 15:11:08 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
	Funcion para comprobar el numero minimo de la pila.
		1º) Inicializo el numero al valor mas grande de INT.
		2º) Dependiendo del mod, recorro la pila "a" o "b".
		3º) Recorro la lista y compruebo si el contenido del nodo es menor
			Si lo es, actualizo el valor de la variable.
*/
void	minstack(t_list *stack, t_stacks *data, char mod)
{
	data->min_a = 2147483647;
	data->min_b = 2147483647;
	if (mod == 'a')
	{
		while (stack != NULL)
		{
			if (stack->content < data->min_a)
				data->min_a = stack->content;
			stack = stack->next;
		}
	}
	else if (mod == 'b')
	{
		while (stack != NULL)
		{
			if (stack->content < data->min_b)
				data->min_b = stack->content;
			stack = stack->next;
		}
	}
}

/*
	Funcion para comprobar el numero maximo de la pila.
		1º) Inicializo el numero al valor mas pequeño de INT.
		2º) Dependiendo del mod, recorro la pila "a" o "b".
		3º) Recorro la pila y compruebo si el contenido del nodo es mayor
			Si lo es, actualizo el valor de la variable.
*/
void	maxstack(t_list *stack, t_stacks *data, char mod)
{
	data->max_a = -2147483648;
	data->max_b = -2147483648;
	if (mod == 'a')
	{
		while (stack != NULL)
		{
			if (stack->content > data->max_a)
				data->max_a = stack->content;
			stack = stack->next;
		}
	}
	else if (mod == 'b')
	{
		while (stack != NULL)
		{
			if (stack->content > data->max_b)
				data->max_b = stack->content;
			stack = stack->next;
		}
	}
}

/*
	Funcion para comprobar la posicion del numero maximo y minimo en la pila.
*/
void	maxminstack(t_list *stack, t_stacks *data, char mod)
{
	maxstack(stack, data, mod);
	minstack(stack, data, mod);
}
