/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbakrim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 17:29:07 by hbakrim           #+#    #+#             */
/*   Updated: 2024/02/14 15:21:05 by hbakrim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

void	ft_error(char *msg)
{
	ft_putendl_fd(msg, 1);
	exit(0);
}

int	check_d(t_list **stack_a)
{
	t_list	*p;
	t_list	*tmp;

	p = *stack_a;
	while (p != NULL && p->next != NULL)
	{
		tmp = p->next;
		while (tmp != NULL)
		{
			if (p->data == tmp->data)
				return (1);
			tmp = tmp->next;
		}
		p = p->next;
	}
	return (0);
}

int	ft_isnum(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_int(char *str)
{
	long long	r;
	int			s;

	r = 0;
	s = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if ((*str == '-' || *str == '+') && *(str + 1))
		if (*str++ == '-')
			s = -1;
	while (*str >= '0' && *str <= '9')
	{
		r = (r * 10) + (*str - '0');
		if (s == -1 && r > 2147483648)
			return (-1);
		if (r > 2147483647 && s == 1)
			return (-1);
		str++;
	}
	if (*str)
		return (-1);
	return (1);
}
