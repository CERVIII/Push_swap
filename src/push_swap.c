/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 12:05:05 by pcervill          #+#    #+#             */
/*   Updated: 2022/12/19 12:08:39 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	leaks(void)
{
	system("leaks -q push_swap");
}

int	ft_error(char *error)
{
	printf("%s%s", RED, error);
	exit(EXIT_FAILURE);
}

int	ft_countword(char *str, char c)
{
	int	i;
	int	wcount;

	i = 0;
	wcount = 0;
	while (str[i])
	{
		if (str[i] != c)
			wcount++;
		i++;
	}
	return (wcount);
}

t_stack	*stackadd(t_stack *stack, int number)
{
	t_stack	*new;
	t_stack	*aux;

	new = (t_stack *) malloc(sizeof(t_stack));
	aux = (t_stack *) malloc(sizeof(t_stack));
	new->content = number;
	new->next = NULL;
	if (stack == NULL)
	{
		stack = new;
	}
	else
	{
		aux = stack;
		while (aux->next)
			aux = aux->next;
		aux->next = new;
	}
	return (stack);
}

t_stack	*checkarg(int argc, char *argv[], t_stacks *data)
{
	int	i;
	int	num;

	i = 0;
	if (argc - 1 == 1)
	{
		argc = ft_countword(argv[i], ' ');
		argv = ft_split(argv[1], ' ');
	}
	while (i < argc && argv[i])
	{
		printf("argv: %s\n", argv[i]);
		num = ft_atoi(argv[i]);
		printf("num: %d\n", num);
		printf("CKP: %d\n", checkparams(argv[i]));
		if ((num == 0 && !ft_isdigit(argv[i][0]) && argv[i][1] != '0') || checkparams(argv[i]) != 0)
			ft_error("Error\nOnly numbers\n");
		data->a = stackadd(data->a, num);
		i++;
	}
	return (data->a);
}

int	main(int argc, char *argv[])
{
	t_stacks	*data;

	atexit(leaks);
	data = (t_stacks *) malloc(sizeof(t_stacks));
	data->a = checkarg(argc, argv, data);
	while (data->a)
	{
		printf("%d\n", data->a->content);
		data->a = data->a->next;
	}
	free(data);
	/* crear una lista y añadir esos numeros a la lista en el mismo orden */
	/* crear los movimientos */
	/* crear el algoritmo para 3 y 5, 100 y 500 numeros */
	return (0);
}
