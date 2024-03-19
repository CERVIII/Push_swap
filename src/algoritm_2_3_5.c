/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritm_2_3_5.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 10:15:37 by pcervill          #+#    #+#             */
/*   Updated: 2024/03/19 15:24:57 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ra_rra(t_list **stack_a, t_stacks *data, int pos)
{
	if (pos < (data->count_a / 2))
		ft_ra(stack_a, data);
	else
		ft_rra(stack_a, data);
	return ;
}

/*
	Funcion para ordenar 2 numeros.
		1º) Compruebo si el primer numero es mayor que el segundo.
		2º) Si lo es, hago un swap.
*/
void	al_two(t_list **stack_a, t_stacks *data)
{
	t_list	*tmp;

	tmp = *stack_a;
	if (tmp->content > tmp->next->content)
		ft_sa(stack_a, data);
}

/*
	Funcion para ordenar 3 numeros
		1º) Creo 3 variables para almacenar el contenido de los nodos.
		2º) Hago un bucle para comprobar si los numeros estan ordenados.
		3º) Gestiono todos los casos posibles para ordenar los numeros.
*/
void	al_three(t_list **stack_a, t_stacks *data)
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
			ft_sa(stack_a, data);
		if (a > b && a > c && b < c)
			ft_ra(stack_a, data);
		if (a < b && a > c && b > c)
			ft_rra(stack_a, data);
	}
}

/*
	Funcion para ordenar 5 numeros:
		1º) Creo un bucle para mover los dos primeros
			numeros max o min mas cercanos al inicio o final.
		2º) Para ello compruebo la posicion del max y el min.
		3º) Si la posicion del max o min es menor que la mitad de la lista,
			hago un ra, si no, hago un rra.
		4º) Cuando tengo los 3 numeros restantes.
		5º) Llamo a la funcion select_al para ordenar los 3 numeros restantes.
		6º) Hago un bucle para mover el contenido de la pila b a la pila a.
			en este paso utilizo ft_move_a para ordenar los numeros dela pila b.
*/
void	al_five(t_list **stack_a, t_list **stack_b, t_stacks *data)
{
	t_list	*tmp;

	tmp = *stack_a;
	while (data->count_b < 2)
	{
		tmp = *stack_a;
		posmaxmin(*stack_a, data, 'a');
		if (tmp->content == data->max_a || tmp->content == data->min_a)
			ft_pb(stack_a, stack_b, data);
		else if (data->count_b == 1)
			ra_rra(stack_a, data, data->max_a);
		else
			ra_rra(stack_a, data, data->min_a);
	}
	select_al(stack_a, stack_b, data);
	while (data->count_b != 0)
	{
		ft_move_a(stack_a, stack_b, data);
	}
	return ;
}

/*
	Funcion
*/
void	ft_move_a(t_list **stack_a, t_list **stack_b, t_stacks *data)
{
	int		a;
	t_list	*tmp;

	tmp = *stack_a;
	a = tmp->content;
	tmp = *stack_b;
	ft_pa(stack_a, stack_b, data);
	if (tmp->content > a)
		ft_ra(stack_a, data);
	return ;
}
