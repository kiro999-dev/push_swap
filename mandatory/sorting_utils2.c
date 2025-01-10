/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhourba <zkhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:49:29 by zkhourba          #+#    #+#             */
/*   Updated: 2025/01/10 17:57:22 by zkhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	its_sorted_des(t_stack *a, int n)
{
	t_stack	*current;
	int		i;
	int		count;

	count = 0;
	if (!a || n <= 1)
		return (1);
	current = a;
	i = 0;
	while (i < n - 1)
	{
		if (current->number < current->next->number)
			count--;
		current = current->next;
		count++;
		i++;
	}
	return (count);
}

int	its_sorted(t_stack *a)
{
	t_stack	*nextptr;

	if (a == NULL || a->next == NULL)
		return (1);
	nextptr = a->next;
	while (nextptr)
	{
		if (a->number > nextptr->number)
			return (0);
		a = a->next;
		nextptr = nextptr->next;
	}
	return (1);
}
