/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 12:26:34 by pcervill          #+#    #+#             */
/*   Updated: 2023/01/11 16:34:09 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	checkparams(char *argv)
{
	int	i;

	i = 1;
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

void	argcheck(char *argv[], t_stacks *data, t_list **stack_a)
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
			if (checkparams(av[j]) != 0)
				ft_error("Only numbers\n");
			ft_write_lst(stack_a, data->num);
			data->count_a++;
			j++;
		}
		ft_freestring(av);
		i++;
	}
	ft_lstorder(stack_a);
	maxminstack(*stack_a, data);
	return ;
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
			ft_error("Repeat numbers\n");
		stack_a = stack_a->next;
	}
	return ;
}
