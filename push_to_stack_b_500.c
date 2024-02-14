/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_stack_b_500.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbakrim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 20:29:18 by hbakrim           #+#    #+#             */
/*   Updated: 2024/02/13 10:12:04 by hbakrim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	declaration_500(int *offset, int *start, int *end, int size)
{
	(*offset) = size / 16;
	(*start) = ((size / 2) - 1) - (*offset);
	(*end) = ((size / 2) - 1) + (*offset);
}

void	push_sort_to_b_500(t_list **stack_a, t_list **stack_b, int arr[],
		int size)
{
	t_list	*head;
	int		offset;
	int		start;
	int		end;

	head = *stack_a;
	declaration_500(&offset, &start, &end, size);
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
