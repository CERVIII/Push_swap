/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritm2_100_500.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:32:40 by pcervill          #+#    #+#             */
/*   Updated: 2024/04/02 15:31:40 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * La función `get_iterative` devuelve la diferencia entre `hold - 1` si `hold`
 * es menor o igual a la
 * mitad de `count`; de lo contrario, devuelve `count - hold + 1`.
 * 
 * @param hold El parámetro `hold` en la función `get_iterative` representa un
 * valor que se compara con la mitad del parámetro `count`.
 * Si "hold" es menor o igual a la mitad de "count", la función
 * devuelve "hold - 1". De lo contrario, devuelve `count - hold + 1`.
 * 
 * @param count El parámetro "count" representa el número total de iteraciones
 * o pasos en un proceso.
 * 
 * @return La función `get_iterative` devuelve `hold - 1` si `hold` es menor
 * o igual a la mitad de `count`, o `count - hold + 1` si `hold` es mayor que
 * la mitad de `count`.
 */
int	get_iterative(int hold, int count)
{
	if (hold <= (count / 2))
		return (hold - 1);
	else
		return (count - hold + 1);
}

/**
 * La función `select_iter` selecciona iterativamente elementos de la pila B
 * y los mueve a la pila A según ciertas condiciones.
 * 
 * @param stack_a El parámetro `stack_a` es un puntero a un puntero a una
 * estructura de lista vinculada `t_list`. Es probable que esta lista vinculada
 * contenga elementos que están siendo manipulados en la función `select_iter`.
 * 
 * @param stack_b El parámetro `stack_b` es un puntero a un puntero a una
 * estructura de lista vinculada `t_list`. Es probable que esta lista vinculada
 * contenga elementos que deban ordenarse o manipularse de alguna manera.
 * La función `select_iter` parece estar iterando sobre los elementos en
 * `stack_b` y realizando ciertas operaciones
 * 
 * @param data El parámetro `data` parece ser una estructura llamada `t_stacks`
 * que contiene al menos los siguientes miembros:
 */
void	select_iter(t_list **stack_a, t_list **stack_b, t_stacks *data)
{
	while (data->posmax_b > 0)
	{
		if (data->count_b > 1)
		{
			if (data->count_b >= 2 && data->flag == 0
				&& (*stack_b)->content == data->cpy[data->count_b - 2])
			{
				ft_pa(stack_a, stack_b, data);
				data->posmax_b = 0;
				data->flag = 1;
			}
			else if (data->hold > (data->count_b / 2))
				ft_rrb(stack_b, data);
			else
				ft_rb(stack_b, data);
		}
		data->posmax_b--;
	}
	if (data->posmax_b == 0)
	{
		ft_pa(stack_a, stack_b, data);
		data->flag = 0;
	}
	free(data->cpy);
}


/**
 * La función `push_to_a` mueve elementos de la pila B a la pila A mientras los
 * clasifica en orden ascendente.
 * 
 * @param stack_a Un puntero a una pila representada como una lista vinculada.
 * 
 * @param stack_b Puntero a una pila que contiene números enteros.
 * 
 * @param data El parámetro "datos" parece ser una estructura llamada "t_stacks"
 * que contiene al menos los siguientes miembros:
 * 		- `posmax_b` Un entero que representa la posición del número máximo en
 * 			la pila B.
 * 		- `hold` Un entero que parece ser un valor que representa el numero de
 * 			movimientos "ra" para que se mueva al primer elemento.
 * 		- `count_b` Un entero que representa el número total de elementos en
 * 			la pila B.
 * 		- `cpy` Un puntero a un entero que parece ser una copia de la pila B.
 * 		- `flag` Un entero que parece ser una bandera que se establece en 0 o 1.
 */
void	push_to_a(t_list **stack_a, t_list **stack_b, t_stacks *data)
{
	while (*stack_b)
	{
		posmaxmin(*stack_b, data, 'b');
		data->hold = data->posmax_b + 1;
		data->posmax_b = get_iterative(data->hold, data->count_b);
		array_sort(*stack_b, data, 'b');
		select_iter(stack_a, stack_b, data);
		ft_ss_sx(stack_a, stack_b, data);
	}
}
