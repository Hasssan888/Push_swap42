/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbakrim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:20:00 by hbakrim           #+#    #+#             */
/*   Updated: 2024/02/14 09:14:56 by hbakrim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_moves(t_list **stack_a, t_list **stack_b, char *line)
{
	if (ft_strcmp(line, "sa\n") == 0)
		return (sa_bonus(stack_a), 1);
	else if (ft_strcmp(line, "sb\n") == 0)
		return (sb_bonus(stack_b), 1);
	else if (ft_strcmp(line, "ra\n") == 0)
		return (ra_bonus(stack_a), 1);
	else if (ft_strcmp(line, "rb\n") == 0)
		return (rb_bonus(stack_b), 1);
	else if (ft_strcmp(line, "rra\n") == 0)
		return (rra_bonus(stack_a), 1);
	else if (ft_strcmp(line, "rrb\n") == 0)
		return (rrb_bonus(stack_b), 1);
	else if (ft_strcmp(line, "pa\n") == 0)
		return (pa_bonus(stack_b, stack_a), 1);
	else if (ft_strcmp(line, "pb\n") == 0)
		return (pb_bonus(stack_a, stack_b), 1);
	else if (ft_strcmp(line, "ss\n") == 0)
		return (ss_bonus(stack_a, stack_b), 1);
	else if (ft_strcmp(line, "rr\n") == 0)
		return (rr_bonus(stack_a, stack_b), 1);
	else if (ft_strcmp(line, "rrr\n") == 0)
		return (rrr_bonus(stack_a, stack_b), 1);
	else
		return (ft_putendl_fd("Error", 1), 0);
}

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

int	read_from_input(t_list **stack_a, t_list **stack_b)
{
	char	*line;

	line = get_next_line(0);
	while (line != NULL)
	{
		if (check_moves(stack_a, stack_b, line) == 0)
		{
			free(line);
			return (0);
		}
		free(line);
		line = get_next_line(0);
	}
	return (1);
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
	stack_b = malloc(sizeof(t_list *));
	*stack_b = NULL;
	if (read_from_input(stack_a, stack_b))
	{
		if (is_sorted(stack_a) && !(*stack_b))
			ft_putendl_fd("OK", 1);
		else
			ft_putendl_fd("KO", 1);
	}
	free_stack(stack_a);
	free_stack(stack_b);
}
