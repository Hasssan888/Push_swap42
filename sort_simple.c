/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbakrim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 20:44:33 by hbakrim           #+#    #+#             */
/*   Updated: 2024/02/04 20:45:51 by hbakrim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_list **stack_a)
{
	t_list	*p;

	p = *stack_a;
	if (is_sorted(stack_a))
		return ;
	if (p->data < p->next->data && p->data < p->next->next->data)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (p->data > p->next->data && p->data < p->next->next->data)
		sa(stack_a);
	else if (p->data < p->next->data && p->data > p->next->next->data)
		rra(stack_a);
	else if (p->data > p->next->data && p->data > p->next->next->data)
	{
		if (p->next->data > p->next->next->data)
		{
			sa(stack_a);
			rra(stack_a);
		}
		else
			ra(stack_a);
	}
}

void	sort_4(t_list **stack_a, t_list **stack_b)
{
	int	index;

	if (is_sorted(stack_a))
		return ;
	index = index_minstack(stack_a);
	if (index == 1)
		ra(stack_a);
	else if (index == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (index == 3)
		rra(stack_a);
	pb(stack_a, stack_b);
	sort_3(stack_a);
	pa(stack_b, stack_a);
}

void	sort_5(t_list **stack_a, t_list **stack_b)
{
	int	index;

	if (is_sorted(stack_a))
		return ;
	index = index_minstack(stack_a);
	if (index == 1)
		ra(stack_a);
	else if (index == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (index == 3)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (index == 4)
		rra(stack_a);
	pb(stack_a, stack_b);
	sort_4(stack_a, stack_b);
	pa(stack_b, stack_a);
}

void	simpel_sort(t_list **stack_a, t_list **stack_b)
{
	int	size;

	if (is_sorted(stack_a) || lst_size(*stack_a) == 0
		|| lst_size(*stack_a) == 1)
		return ;
	size = lst_size(*stack_a);
	if (size == 2)
		sa(stack_a);
	else if (size == 3)
		sort_3(stack_a);
	else if (size == 4)
		sort_4(stack_a, stack_b);
	else if (size == 5)
		sort_5(stack_a, stack_b);
}
