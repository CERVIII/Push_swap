/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 12:26:34 by pcervill          #+#    #+#             */
/*   Updated: 2023/02/28 13:04:01 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	checkparams(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if ((argv[i] < '0' || argv[i] > '9') && argv[i] != '-')
			return (1);
		if (argv[i + 1] == '-')
			return (1);
		i++;
	}
	return (0);
}

void	ft_write_lst(t_list **stack_a, int num)
{
	t_list	*tmp;

	tmp = NULL;
	tmp = ft_lstnew(num);
	ft_lstadd_back(stack_a, tmp);
	ft_isrepeat(*stack_a, num);
	tmp = NULL;
}

void	ft_isrepeat(t_list *stack_a, int num)
{
	while (stack_a->next != NULL)
	{
		if (stack_a->content == num)
			ft_error();
		stack_a = stack_a->next;
	}
	return ;
}

void	argcheck(char *argv[], t_list **stack_a)
{
	char	**av;
	int		i;
	int		j;

	i = 1;
	while (argv[i])
	{
		if (ft_strlen(argv[i]) == 0 || (ft_strlen(argv[i]) == 1
				&& (argv[i][0] == ' ' || argv[i][0] == '-')))
			ft_error();
		av = ft_split(argv[i], ' ');
		j = 0;
		while (av[j])
		{
			if (checkparams(av[j]) != 0)
				ft_error();
			ft_write_lst(stack_a, ft_atoi(av[j]));
			j++;
		}
		ft_freestr(av);
		i++;
	}
	ft_lstorder(stack_a);
	return ;
}
