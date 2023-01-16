/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 12:05:05 by pcervill          #+#    #+#             */
/*   Updated: 2023/01/16 17:29:27 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	leaks(void)
{
	system("leaks -q push_swap");
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

void	example_movs(t_list **stack_a, t_list **stack_b)
{
	ft_sa(stack_a);
	ft_printst(*stack_a, *stack_b);
	ft_pb(stack_a, stack_b);
	ft_pb(stack_a, stack_b);
	ft_pb(stack_a, stack_b);
	ft_printst(*stack_a, *stack_b);
	ft_sb(stack_b);
	ft_printst(*stack_a, *stack_b);
	ft_ss(stack_a, stack_b);
	ft_printst(*stack_a, *stack_b);
	ft_ra(stack_a);
	ft_printst(*stack_a, *stack_b);
	ft_rb(stack_b);
	ft_printst(*stack_a, *stack_b);
	ft_rr(stack_a, stack_b);
	ft_printst(*stack_a, *stack_b);
	ft_rra(stack_a);
	ft_printst(*stack_a, *stack_b);
	ft_rrb(stack_b);
	ft_printst(*stack_a, *stack_b);
	ft_rrr(stack_a, stack_b);
	ft_printst(*stack_a, *stack_b);
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
	example_movs(&stack_a, &stack_b);
	stackclear(&stack_a);
	free(data);
	/* crear el algoritmo para 3 y 5, 100 y 500 numeros */
	return (0);
}
