/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 12:26:34 by pcervill          #+#    #+#             */
/*   Updated: 2022/12/21 13:45:51 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_countspace(char *str, char c)
{
	int	i;
	int	wcount;

	i = 0;
	wcount = 0;
	while (str[i])
	{
		if (str[i] == c)
			wcount++;
		i++;
	}
	return (wcount);
}

int	ft_countword(char *str, char c)
{
	int	i;
	int	wcount;

	i = 0;
	wcount = 0;
	while (str[i])
	{
		if (str[i] != c && (str[i + 1] == ' ' || str[i + 1] == '\0'))
			wcount++;
		i++;
	}
	return (wcount);
}

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

void	ft_freestring(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	argcheck(char *argv[], t_stacks *data)
{
	char	**av;
	int		i;
	int		j;

	i = 1;
	while (argv[i])
	{
		av = ft_split(argv[i], ' ');
		j = 0;
		while (av[j])
		{
			data->num = ft_atoi(av[j]);
			if ((data->num == 0 && !ft_isdigit(av[j][0])
				&& av[j][1] != '0') || checkparams(av[j]) != 0)
				ft_error("Error\nOnly numbers\n");
			data->a = stackadd(data->a, data->num);
			j++;
		}
		ft_freestring(av);
		i++;
	}
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
