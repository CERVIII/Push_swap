/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 12:26:34 by pcervill          #+#    #+#             */
/*   Updated: 2024/03/19 13:37:59 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
	Funcion para comprobar que los argumentos pasados son numeros y
	no contienen caracteres no validos.
*/
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

/*
	Funcion para crear los nodos de la lista, comprobando que no se repitan
	los numeros.
		1º) Creo un nodo con el numero pasado como argumento. (ft_lstnew)
		2º) Añado el nodo al final de la lista. (ft_lstadd_back)
		3º) Compruebo que no se repitan los numeros. (ft_isrepeat)
		
*/
void	ft_write_lst(t_list **stack_a, int num)
{
	t_list	*tmp;

	tmp = NULL;
	tmp = ft_lstnew(num);
	ft_lstadd_back(stack_a, tmp);
	ft_isrepeat(*stack_a, num);
}

/*
	Funcion para comprobar que no se repitan los numeros.
		1º) Recorro la lista y comparo el numero pasado como argumento
			con el contenido de cada nodo.
		2º) Si el numero ya existe en la lista, salta un error.
*/
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

/*
	Funcion encargada de gestionar el parseo de argumentos, pueden ser argumentos
	sueltos o entre comillas.
		1º) Recorre la lista desde el primer argumento y mediante el strlen
			comprueba si es un argumento simple o entre comillas, ademas de
			comprobar que no sea nulo o que sea un espacio o un guion unicamente.
		2º) Si es un argumento entre comillas, lo separa en palabras y entra en
			checkparams para comprobar que sean numeros.
		3º) Si es un argumento valido, entra en ft_write_lst para ir creando
			los nodos de la lista haciendo un atoi de los argumentos.
		4º) Con la funcion ft_lstorder compruebo si los argumentos pasados estan
			ordenados, si es asi salgo del programa.
*/
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
