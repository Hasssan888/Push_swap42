/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbakrim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:14:27 by hbakrim           #+#    #+#             */
/*   Updated: 2024/02/14 09:13:46 by hbakrim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrb_bonus(t_list **stack_b)
{
	reverse_rotate(stack_b);
}

void	pa_bonus(t_list **stack_b, t_list **stack_a)
{
	push(stack_b, stack_a);
}

void	pb_bonus(t_list **stack_a, t_list **stack_b)
{
	push(stack_a, stack_b);
}
