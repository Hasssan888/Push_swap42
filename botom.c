/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   botom.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbakrim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:07:35 by hbakrim           #+#    #+#             */
/*   Updated: 2024/02/14 10:43:37 by hbakrim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	search(t_list **stack_b, int elem)
{
	t_list	*tmp;

	tmp = *stack_b;
	while (tmp != NULL)
	{
		if (tmp->data == elem)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	botom_0(t_list **stack_b, t_list **stack_a, t_list **head, int *botom)
{
	pa(stack_b, stack_a);
	ra(stack_a);
	*head = *stack_b;
	(*botom)++;
}

void	botom_1(t_list **stack_b, t_list **stack_a, int elem, int *botom)
{
	if (search(stack_b, elem) == 1)
	{
		bestmov_b(stack_b);
		pa(stack_b, stack_a);
	}
	else if (search(stack_b, elem) == 0)
	{
		rra(stack_a);
		(*botom)--;
	}
}
