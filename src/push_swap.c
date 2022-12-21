/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 12:05:05 by pcervill          #+#    #+#             */
/*   Updated: 2022/12/21 15:35:54 by pcervill         ###   ########.fr       */
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

int	main(int argc, char *argv[])
{
	t_stacks	*data;

	atexit(leaks);
	data = (t_stacks *) malloc(sizeof(t_stacks));
	if (argc == 1)
		ft_error("Error\nFaltan Argumentos");
	argcheck(argv, data);
	//data->count_a = stacksize(data->a);
	//maxminstack(data, data->a);
	//printf("count A: %d, max A: %d, min A: %d\n", data->count_a, data->max, data->min);
	data->a = stackclear(data->a);
	free(data);
	/* crear una lista y añadir esos numeros a la lista en el mismo orden */
	/* crear los movimientos */
	/* crear el algoritmo para 3 y 5, 100 y 500 numeros */
	return (0);
}
