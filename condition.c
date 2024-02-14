/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   condition.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbakrim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 17:39:33 by hbakrim           #+#    #+#             */
/*   Updated: 2024/02/04 17:42:37 by hbakrim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max(t_list **stack)
{
	t_list	*head;
	int		max;

	head = *stack;
	max = head->data;
	while (head != NULL)
	{
		if (max < head->data)
			max = head->data;
		head = head->next;
	}
	return (max);
}

int	index_stack(t_list **stack)
{
	t_list	*head;
	int		index;
	int		max;

	max = get_max(stack);
	head = *stack;
	index = 0;
	while (head != NULL)
	{
		if (head->data == max)
			break ;
		index++;
		head = head->next;
	}
	return (index);
}

int	get_min(t_list **stack)
{
	t_list	*head;
	int		min;

	head = *stack;
	min = head->data;
	while (head != NULL)
	{
		if (min > head->data)
			min = head->data;
		head = head->next;
	}
	return (min);
}

int	index_minstack(t_list **stack)
{
	t_list	*head;
	int		index;
	int		min;

	min = get_min(stack);
	head = *stack;
	index = 0;
	while (head != NULL)
	{
		if (head->data == min)
			break ;
		index++;
		head = head->next;
	}
	return (index);
}
