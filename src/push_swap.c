/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 12:05:05 by pcervill          #+#    #+#             */
/*   Updated: 2022/12/14 18:17:43 by pcervill         ###   ########.fr       */
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

/* char	*savenum(char *argv[], t_stacks *data)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		if (argv[i][0] == '"')
		{
			while (argv[i][j])
			{
				if ((argv[i][j] < '0' || argv[i][j] > '9') && argv[i][j] != '-')
					ft_error("ERROR\nArgumentos no validos(LETRAS?)");
				if (argv[i][j + 1] == '-')
					ft_error("ERROR\nArgumentos no validos(LETRAS?)");
				j++;
			}
		}
	}
}
 */
int	main(int argc, char *argv[])
{
	int			i;
	int			j;
	t_stacks	*data;

	atexit(leaks);
	data = (t_stacks *) malloc(sizeof(t_stacks));
	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
			printf("%c\n", argv[i][j++]);
		i++;
	}
	checkparams(argc, argv);
	data->number = strnumber(argc, argv);
	i = 0;
	while (data->number[i])
		printf("%d\n", data->number[i++]);
	free(data);
	/* crear una lista y añadir esos numeros a la lista en el mismo orden */
	/* crear los movimientos */
	/* crear el algoritmo para 3 y 5, 100 y 500 numeros */
	return (0);
}
