/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbakrim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 20:20:29 by hbakrim           #+#    #+#             */
/*   Updated: 2024/02/14 09:12:56 by hbakrim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **stack_a)
{
	swap_r(stack_a);
	ft_putendl_fd("sa", 1);
}

void	sb(t_list **stack_b)
{
	swap_r(stack_b);
	ft_putendl_fd("sb", 1);
}

void	ra(t_list **stack_a)
{
	rotate(stack_a);
	ft_putendl_fd("ra", 1);
}

void	rb(t_list **stack_b)
{
	rotate(stack_b);
	ft_putendl_fd("rb", 1);
}

void	rra(t_list **stack_a)
{
	reverse_rotate(stack_a);
	ft_putendl_fd("rra", 1);
}
