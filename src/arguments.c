/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 12:26:34 by pcervill          #+#    #+#             */
/*   Updated: 2022/12/19 17:51:00 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

/* static void	ft_freestring(char **str, size_t cstr)
{
	while (cstr > 0)
	{
		free(str[cstr]);
		cstr--;
	}
	free(str);
} */

void	checkarg(int argc, char *argv[])
{
	int	i;
	int	num;

	i = 0;
	if (argc - 1 == 1)
	{
		argc = ft_countword(argv[i], ' ');
		argv = ft_split(argv[1], ' ');
	}
	else
		i = 1;
	while (i < argc && argv[i])
	{
		num = ft_atoi(argv[i]);
		printf("%d", num);
		if ((num == 0 && !ft_isdigit(argv[i][0])
			&& argv[i][1] != '0') || checkparams(argv[i]) != 0)
			ft_error("Error\nOnly numbers\n");
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
