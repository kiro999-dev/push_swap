/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhourba <zkhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:46:39 by zkhourba          #+#    #+#             */
/*   Updated: 2025/01/12 16:24:00 by zkhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*biggest_index(t_stack *b)
{
	int		max;
	t_stack	*biggest;

	max = INT_MIN;
	while (b)
	{
		if (max <= b->index)
		{
			max = b->index;
			biggest = b;
		}
		b = b->next;
	}
	return (biggest);
}

void	new_pos(t_stack *b)
{
	int	i;

	i = 0;
	while (b)
	{
		b->pos = i;
		i++;
		b = b->next;
	}
}

void	index_init(t_stack *top)
{
	while (top)
	{
		top->index = 0;
		top = top->next;
	}
}

void	indexing_num(t_stack *num, t_stack *top)
{
	while (top)
	{
		if (num->number > top->number)
			num->index++;
		top = top->next;
	}
}

void	indexing_list(t_stack *top)
{
	t_stack	*ptr1;

	ptr1 = top;
	while (ptr1)
	{
		indexing_num(ptr1, top);
		ptr1 = ptr1->next;
	}
}
