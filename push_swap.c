/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbakrim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 17:55:36 by hbakrim           #+#    #+#             */
/*   Updated: 2024/02/14 10:45:31 by hbakrim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	whiloop(t_list **stack_a, char **strs)
{
	int	j;

	j = 0;
	while (strs[j])
	{
		if (check_int(strs[j]) == -1)
		{
			free(strs[j]);
			ft_error("Error");
			exit(1);
		}
		lstadd_back(stack_a, create_node(ft_atoi(strs[j])));
		free(strs[j]);
		j++;
	}
}

void	cpyargv_tostack(t_list **stack_a, int ac, char **av)
{
	char	**strs;
	int		i;

	i = 1;
	while (i < ac)
	{
		strs = ft_split(av[i], ' ');
		if (!strs)
		{
			ft_error("Error");
			exit(1);
		}
		whiloop(stack_a, strs);
		free(strs);
		i++;
	}
}

void	sortstack(t_list **stack_a, t_list **stack_b)
{
	if (lst_size(*stack_a) <= 5)
		simpel_sort(stack_a, stack_b);
	else
		sort_comple(stack_a, stack_b);
}

int	main(int ac, char **av)
{
	t_list	**stack_a;
	t_list	**stack_b;

	if (ac < 2)
		return (-1);
	stack_a = malloc(sizeof(t_list *));
	*stack_a = NULL;
	cpyargv_tostack(stack_a, ac, av);
	if (check_d(stack_a) == 1)
	{
		ft_error("Error");
		free_stack(stack_a);
	}
	if (is_sorted(stack_a))
	{
		free_stack(stack_a);
		return (0);
	}
	stack_b = malloc(sizeof(t_list *));
	*stack_b = NULL;
	sortstack(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
}
