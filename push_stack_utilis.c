/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack_utilis.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbakrim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:06:55 by hbakrim           #+#    #+#             */
/*   Updated: 2024/02/14 10:46:04 by hbakrim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_or_not(t_list **stack_a, int tab[], int start, int end)
{
	t_list	*tmp;

	tmp = (*stack_a);
	if (!(tmp->next))
		return (0);
	while (tmp)
	{
		if (tmp->data >= tab[start] && tmp->data <= tab[end])
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	position(t_list **stack_a, int *tab, int start, int end)
{
	t_list	*tmp;
	int		i;

	tmp = (*stack_a);
	i = 0;
	while (tmp)
	{
		if (tmp->data >= tab[start] && tmp->data <= tab[end])
			break ;
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int	bestmove(t_list **stack_a, int arr[], int start, int end)
{
	int	j;

	if (*stack_a == NULL)
		return (0);
	if (find_or_not(stack_a, arr, start, end) == 1)
	{
		j = position(stack_a, arr, start, end);
		while (j > 0)
		{
			ra(stack_a);
			j--;
		}
		return (1);
	}
	return (0);
}

void	modif_start_end(int *start, int *end, int *offset, int size)
{
	(*start) -= (*offset);
	if ((*start) < 0)
		(*start) = 0;
	(*end) += (*offset);
	if ((*end) >= size)
		(*end) = size - 1;
}
