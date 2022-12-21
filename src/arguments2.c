/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 09:52:29 by pcervill          #+#    #+#             */
/*   Updated: 2022/12/21 13:36:48 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	argcheck(char *argv[], t_stacks *data)
{
	int		ac;
	char	**av;
	int		i;
	int		j;

	i = 1;
	while (argv[i])
	{
		ac = ft_countword(argv[i], ' ');
		printf("W: %d\n", ac);
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
		ac--;
		ft_freestring(av);
		i++;
	}
}
