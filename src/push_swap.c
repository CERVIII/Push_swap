/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 12:05:05 by pcervill          #+#    #+#             */
/*   Updated: 2023/01/23 17:35:18 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	leaks(void)
{
	system("leaks -q push_swap");
}

void	select_al(t_list **stack_a, t_list **stack_b, t_stacks *data)
{
	t_list	*tmp;

	tmp = *stack_b;
	if (data->count_a == 3)
	{
		al_three(stack_a, data);
		return ;
	}
	if (data->count_a == 5)
	{
		al_five(stack_a, stack_b, data);
		return ;
	}
	free(stack_b);
}

void	ft_printst(t_list *stack_a, t_list *stack_b)
{
	printf("STACK A:	STACK B:\n");
	while (stack_a || stack_b)
	{
		if (stack_a)
		{
			printf("%d", stack_a->content);
			stack_a = stack_a->next;
		}
		if (stack_b)
		{
			printf("		%d\n", stack_b->content);
			stack_b = stack_b->next;
		}
		if (!stack_b)
			printf("\n");
	}
	return ;
}

void	initdata(t_stacks *data)
{
	data->count_a = 0;
	data->count_b = 0;
	data->movs = 0;
	data->max = 0;
	data->min = 0;
	data->num = 0;
}

int	main(int argc, char *argv[])
{
	t_stacks	*data;
	t_list		*stack_a;
	t_list		*stack_b;

	atexit(leaks);
	stack_a = NULL;
	stack_b = NULL;
	data = (t_stacks *) malloc(sizeof(t_stacks));
	initdata(data);
	if (!data)
		exit (1);
	if (argc < 2)
		ft_error("Faltan Argumentos.\n");
	argcheck(argv, data, &stack_a);
	select_al(&stack_a, &stack_b, data);
	printf("Nº MOVIMIENTOS: %d\n", data->movs);
	ft_printst(stack_a, stack_b);
	stackclear(&stack_a);
	free(data);
	/* crear el algoritmo para 5, 100 y 500 numeros */
	return (0);
}
