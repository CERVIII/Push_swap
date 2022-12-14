/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 12:26:34 by pcervill          #+#    #+#             */
/*   Updated: 2022/12/13 12:47:22 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	checkparams(int argc, char *argv[])
{
	int	i;
	int	j;

	if (argc < 2)
		ft_error("ERROR\nArgumentos no validos(NUMERO ARGUMENTOS)\n");
	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] < '0' || argv[i][j] > '9') && argv[i][j] != '-'
				&& argv[i][j] != ' ')
				ft_error("ERROR\nArgumentos no validos(LETRAS?)");
			if (argv[i][j + 1] == '-')
				ft_error("ERROR\nArgumentos no validos(LETRAS?)");
			j++;
		}
		i++;
	}
	return ;
}

int	*strnumber(int argc, char **argv)
{
	int	*number;
	int	i;
	int	j;
	int	len;

	number = (int *) malloc(argc * sizeof(int));
	if (!number)
		return (0);
	i = 1;
	j = 0;
	while (argv[i])
	{
		len = ft_strlen(argv[i]);
		number[j] = ft_atoi(argv[i++]);
		if (len > 1 && (number[j] == -1 || number[j] == 0))
			ft_error("ERROR\nArgumentos no validos(TAMAÑO INT)");
		j++;
	}
	number[j] = '\0';
	free(number);
	return (number);
}
