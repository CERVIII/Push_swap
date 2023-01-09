/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movs1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:22:32 by pcervill          #+#    #+#             */
/*   Updated: 2023/01/09 12:31:22 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sa(t_stacks *data)
{
	t_stack	swap;

	swap = (t_stack *) malloc(sizeof(t_stack));
	data->a->next = swap;
	data->a = data->next;
	data->a = swap;
	data->a->
}