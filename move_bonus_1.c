/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbakrim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:15:09 by hbakrim           #+#    #+#             */
/*   Updated: 2024/02/14 09:13:36 by hbakrim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_bonus(t_list **stack_a)
{
	swap_r(stack_a);
}

void	sb_bonus(t_list **stack_b)
{
	swap_r(stack_b);
}

void	ra_bonus(t_list **stack_a)
{
	rotate(stack_a);
}

void	rb_bonus(t_list **stack_b)
{
	rotate(stack_b);
}

void	rra_bonus(t_list **stack_a)
{
	reverse_rotate(stack_a);
}
