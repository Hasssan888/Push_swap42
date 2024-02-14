/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_stack_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbakrim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 13:24:51 by hbakrim           #+#    #+#             */
/*   Updated: 2024/02/14 10:43:15 by hbakrim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bestmov_b(t_list **stack_b)
{
	int	i;
	int	size_b;

	i = index_stack(stack_b);
	size_b = lst_size(*stack_b);
	if (i <= size_b / 2)
	{
		while (i > 0)
		{
			rb(stack_b);
			i--;
		}
	}
	else
	{
		while (i <= size_b - 1)
		{
			rrb(stack_b);
			i++;
		}
	}
}

void	move(t_list **stack_b, t_list **stack_a, t_list **head, int *size)
{
	bestmov_b(stack_b);
	pa(stack_b, stack_a);
	*head = *stack_b;
	(*size)--;
}

void	norminette(t_list **stack_a, int botom)
{
	while (botom != 0)
	{
		rra(stack_a);
		botom--;
	}
}

void	norminette_1(t_list **stack_b, t_list **stack_a, int *size,
		t_list **head)
{
	pa(stack_b, stack_a);
	(*size)--;
	*head = *stack_b;
}

void	push_sort_to_a(t_list **stack_b, t_list **stack_a, int arr[], int size)
{
	t_list	*head;
	int		botom;

	move(stack_b, stack_a, &head, &size);
	botom = 0;
	while (head != NULL)
	{
		if (arr[size - 1] == head->data)
			norminette_1(stack_b, stack_a, &size, &head);
		else
		{
			if (botom == 0 || head->data > lstlast(*stack_a)->data)
				botom_0(stack_b, stack_a, &head, &botom);
			else if (head->data < lstlast(*stack_a)->data)
			{
				botom_1(stack_b, stack_a, arr[size - 1], &botom);
				head = *stack_b;
				size--;
			}
		}
	}
	norminette(stack_a, botom);
}
