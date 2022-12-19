/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 12:26:34 by pcervill          #+#    #+#             */
/*   Updated: 2022/12/19 11:02:43 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	checkparams(char *argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if ((argv[i] < '0' || argv[i] > '9') && argv[i] != '-'
			&& argv[i] != ' ')
			return (1);
		if (argv[i + 1] == '-')
			return (1);
		i++;
	}
	return (0);
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
