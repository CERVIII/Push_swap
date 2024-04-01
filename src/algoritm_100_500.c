/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritm_100_500.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:10:12 by pcervill          #+#    #+#             */
/*   Updated: 2024/04/01 13:16:54 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
	Funcion para calcular el tamaño de los bloques segun la cantidad de numeros
	que se manden, es decir por cada bloque habra 50, 20 o 5 numeros.
*/
void	chunkslen(t_stacks *data)
{
	if (data->count_a >= 100 && data->count_a < 500)
		data->chunks = 20;
	else if (data->count_a >= 500)
		data->chunks = 50;
	else
		data->chunks = 5;
}

/*
	Funcion para empujar el numero menor a la pila b.
		1º) Creo una variable para el tamaño de la pila.
		2º) Creo una variable para el bloque de numeros.
		3º) Creo una variable para el ultimo numero de la pila.
		4º) Empujo el numero a la pila b.
		5º) Compruebo el tamaño de la pila.
		6º) Si el tamaño es mayor o igual a 500, el bloque es de 25.
		7º) Si el tamaño es mayor o igual a 100 y menor a 500, el bloque es de 10.
		8º) Si el tamaño es mayor a 5, el bloque es de 3.
		9º) Si la pila b tiene mas de 2 numeros y el contenido del primer nodo
			es menor que el numero del bloque y la pila a tiene mas de 2 numeros
			y el contenido del primer nodo es mayor que el ultimo numero, hago
			una rotacion de ambas pilas.
		10º) Si la pila b tiene mas de 2 numeros y el contenido del primer nodo
			es menor que el numero del bloque, hago una rotacion de la pila b.
*/
void	push_min(t_list **stack_a, t_list **stack_b, t_stacks *data, int i)
{
	int	size;
	int	block;

	block = 0;
	ft_pb(stack_a, stack_b, data);
	size = data->count_a + data->count_b;
	if (size >= 500)
		block = 25;
	else if (size >= 100 && size < 500)
		block = 10;
	else if (size > 5)
		block = 3;
	if (data->count_b >= 2 && (*stack_b)->content < data->cpy[i - block]
		&& data->count_a >= 2 && (*stack_a)->content > data->lastnum)
		ft_rr(stack_a, stack_b, data);
	if (data->count_b >= 2 && (*stack_b)->content < data->cpy[i - block])
		ft_rb(stack_b, data);
}

void	rotate_max(t_list **stack_a, t_list **stack_b, t_stacks *data, int i)
{
	int	size;
	int	block;

	block = 0;
	size = data->count_a + data->count_b;
	if (size >= 500)
		block = 25;
	else if (size >= 100 && size < 500)
		block = 10;
	else if (size > 5)
		block = 3;
	if (data->count_b >= 2 && (*stack_b)->content < data->cpy[i - block])
		ft_rr(stack_a, stack_b, data);
	else
		ft_ra(stack_a, data);
}

/*
	Funcion para empujar los numeros de la pila A a la pila B, segun los
	bloques establecidos
*/
void	push_to_b(t_list **stack_a, t_list **stack_b, t_stacks *data)
{
	int	i;
	int	size;

	i = data->chunks;
	size = data->count_a + data->count_b;
	data->lastnum = data->cpy[i];
	while (data->count_a > 1)
	{
		while (data->count_b < i)
		{
			if (data->lastnum > (*stack_a)->content || i == size)
				push_min(stack_a, stack_b, data, i);
			else
				rotate_max(stack_a, stack_b, data, i);
		}
		i = i + data->chunks;
		if (i < size)
			data->lastnum = data->cpy[i];
		else
		{
			data->lastnum = data->cpy[size - 1];
			i = size;
		}
	}
}

/*
	Funcion para ordenar mas de 5 numeros:
		1º) Creo una copia de la pila A y la ordeno.
		2º) Calculo el tamaño de los bloques.
		3º) Empujo los numeros de la pila A a la pila B, segun esten al principio
			y siempre que sean mas pequeños que el numero maximo y
			haciendo grupos de x.
*/
void	al_hundred(t_list **stack_a, t_list **stack_b, t_stacks *data)
{
	array_sort(*stack_a, data, 'a');
	chunkslen(data);
	push_to_b(stack_a, stack_b, data);
	free(data->cpy);
	push_to_a(stack_a, stack_b, data);
}
