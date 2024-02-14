/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_stack_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbakrim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 14:37:30 by hbakrim           #+#    #+#             */
/*   Updated: 2024/02/04 14:46:31 by hbakrim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	declaration(int *offset, int *start, int *end, int size)
{
	int	div;

	div = size / 2;
	(*offset) = size / div;
	(*start) = ((size / 2) - 1) - (*offset);
	(*end) = ((size / 2) - 1) + (*offset);
}

void	push_sort_to_b(t_list **stack_a, t_list **stack_b, int arr[], int size)
{
	t_list	*head;
	int		offset;
	int		start;
	int		end;

	head = *stack_a;
	declaration(&offset, &start, &end, size);
	while (head != NULL)
	{
		if (head->data >= arr[start] && head->data <= arr[end])
		{
			pb(stack_a, stack_b);
			if (head->data < arr[(size / 2) - 1] && (*stack_b)->next)
				rb(stack_b);
			head = *stack_a;
		}
		else
		{
			if (bestmove(stack_a, arr, start, end) == 1)
				head = *stack_a;
			else
				modif_start_end(&start, &end, &offset, size);
		}
	}
}
