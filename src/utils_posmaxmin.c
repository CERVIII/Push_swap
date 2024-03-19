/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_posmaxmin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 12:29:15 by pcervill          #+#    #+#             */
/*   Updated: 2024/03/19 15:08:12 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
	Funcion para comprobar la posicion del numero maximo de la pila
		1º) Inicializo la variable de posicion en 0.
		2º) Dependiendo del mod, recorro la pila "a" o "b.
		3º) Recorro la pila y voy avanzando el contador de posicion.
		4º) Compruebo si el contenido del nodo es igual al numero maximo.
			Si lo es, salgo de la funcion.
*/
void	posmax(t_list *stack, t_stacks *data, char mod)
{
	data->posmax_a = 0;
	data->posmax_b = 0;
	maxstack(stack, data, mod);
	if (mod == 'a' && data->count_a != 0)
	{
		while (stack->content != data->max_a)
		{
			if (stack->content != data->max_a)
				data->posmax_a++;
			stack = stack->next;
		}
	}
	else if (mod == 'b' && data->count_b != 0)
	{
		while (stack->content != data->max_b)
		{
			data->posmax_b++;
			stack = stack->next;
		}
	}
	return ;
}

/*
	Funcion para comprobar la posicion del numero minimo de la pila
		1º) Inicializo la variable de posicion en 0.
		2º) Dependiendo del mod, recorro la pila "a" o "b".
		3º) Recorro la pila y voy avanzando el contador de posicion.
		4º) Compruebo si el contenido del nodo es igual al numero minimo.
			Si lo es, salgo de la funcion.
*/
void	posmin(t_list *stack, t_stacks *data, char mod)
{
	minstack(stack, data, mod);
	if (mod == 'a' && data->count_a != 0)
	{
		data->posmin_a = 0;
		while (stack->content != data->min_a)
		{
			data->posmin_a++;
			stack = stack->next;
		}
	}
	else if (mod == 'b' && data->count_b != 0)
	{
		data->posmin_b = 0;
		while (stack->content != data->min_b)
		{
			data->posmin_b++;
			stack = stack->next;
		}
	}
	return ;
}

/*
	Funcion para comprobar la posicion en la que se encuentran el numero
	en la pila "a" o "b" segun el mod.
*/
void	posmaxmin(t_list *stack, t_stacks *data, char mod)
{
	posmax(stack, data, mod);
	posmin(stack, data, mod);
	return ;
}
