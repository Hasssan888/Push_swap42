/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbakrim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 20:32:26 by hbakrim           #+#    #+#             */
/*   Updated: 2024/02/14 09:14:20 by hbakrim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_r(t_list **stack)
{
	int	swap;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	swap = (*stack)->data;
	(*stack)->data = (*stack)->next->data;
	(*stack)->next->data = swap;
}

void	rotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*head;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	tmp = *stack;
	head = tmp->next;
	tmp->next = NULL;
	lstadd_back(&head, tmp);
	*stack = head;
}

void	reverse_rotate(t_list **stack)
{
	t_list	*last;
	t_list	*head;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	last = *stack;
	last = lstlast(last);
	head = *stack;
	while (head->next != NULL)
	{
		if (head->next->next == NULL)
		{
			head->next = NULL;
			break ;
		}
		head = head->next;
	}
	lstadd_front(stack, last);
}

void	push(t_list **stack_1, t_list **stack_2)
{
	t_list	*tmp1;
	t_list	*tmp2;

	if (*stack_1 == NULL)
		return ;
	tmp1 = *stack_1;
	tmp2 = *stack_1;
	if (*stack_2 == NULL)
	{
		tmp2 = tmp2->next;
		tmp1->next = NULL;
		*stack_2 = tmp1;
		*stack_1 = tmp2;
	}
	else
	{
		tmp2 = tmp2->next;
		tmp1->next = NULL;
		lstadd_front(stack_2, tmp1);
		*stack_1 = tmp2;
	}
}
