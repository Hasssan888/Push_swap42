/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_comple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbakrim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 20:42:13 by hbakrim           #+#    #+#             */
/*   Updated: 2024/02/07 18:51:50 by hbakrim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*copy_to_arr(t_list **stack_a)
{
	t_list	*ptr;
	int		*arr;
	int		i;
	int		size;

	size = lst_size(*stack_a);
	arr = malloc(sizeof(int) * size);
	if (arr == NULL)
		return (NULL);
	i = 0;
	ptr = *stack_a;
	while (ptr != NULL)
	{
		arr[i] = ptr->data;
		ptr = ptr->next;
		i++;
	}
	return (arr);
}

void	sort_comple(t_list **stack_a, t_list **stack_b)
{
	int	*arr;
	int	size;

	arr = copy_to_arr(stack_a);
	size = lst_size(*stack_a);
	bubble_sort(arr, size);
	if (size == 100)
		push_sort_to_b_100(stack_a, stack_b, arr, size);
	else if (size == 500)
		push_sort_to_b_500(stack_a, stack_b, arr, size);
	else
		push_sort_to_b(stack_a, stack_b, arr, size);
	push_sort_to_a(stack_b, stack_a, arr, size);
	free(arr);
}
