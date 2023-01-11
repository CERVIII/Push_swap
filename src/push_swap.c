/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 12:05:05 by pcervill          #+#    #+#             */
/*   Updated: 2023/01/11 17:54:53 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	leaks(void)
{
	system("leaks -q push_swap");
}

void	ft_printst(t_list *stack)
{
	while (stack)
	{
		printf("%d\n", stack->content);
		stack = stack->next;
	}
	return ;
}

void	initdata(t_stacks *data)
{
	data->count_a = 0;
	data->count_b = 0;
	data->num = 0;
	data->max = 0;
	data->min = 0;
}

int	main(int argc, char *argv[])
{
	t_stacks	*data;
	t_list		*stack_a;

	atexit(leaks);
	stack_a = NULL;
	data = (t_stacks *) malloc(sizeof(t_stacks));
	initdata(data);
	if (!data)
		exit (1);
	if (argc < 2)
		ft_error("Faltan Argumentos.\n");
	argcheck(argv, data, &stack_a);
	ft_printst(stack_a);
	ft_sa(&stack_a);
	ft_printst(stack_a);
	stackclear(&stack_a);
	free(data);
	/* crear los movimientos */
	/* crear el algoritmo para 3 y 5, 100 y 500 numeros */
	return (0);
}
