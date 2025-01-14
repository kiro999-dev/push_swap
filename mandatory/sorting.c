/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhourba <zkhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:21:57 by zkhourba          #+#    #+#             */
/*   Updated: 2025/01/13 19:37:25 by zkhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_5(t_stack **a, t_stack **b)
{
	t_stack	*smallest;

	smallest = smallest_index(*a);
	while (*a != smallest)
	{
		if (smallest->pos <= 2)
			r(a, 1);
		else
			rev_r(a, 1);
		new_pos(*a);
	}
	pb(a, b);
	smallest = smallest_index(*a);
	while (*a != smallest)
	{
		if (smallest->pos <= 2)
			r(a, 1);
		else
			rev_r(a, 1);
		new_pos(*a);
	}
	pb(a, b);
	mini_sort(a, 3);
	pa(a, b);
	pa(a, b);
}

void	sort_the_des_list(t_stack **a, t_stack **b, int n, int range)
{
	t_stack	*top;
	int		i;

	i = 0;
	while (i < n)
	{
		top = *a;
		if (top->index <= i)
		{
			pb(a, b);
			i++;
		}
		else if (top->index <= (i + range))
		{
			pb(a, b);
			r(b, 0);
			i++;
		}
		else
			rev_r(a, 1);
	}
}

void	sort_the_list(t_stack **a, t_stack **b, int n, int range)
{
	t_stack	*top;
	int		i;

	i = 0;
	while (i < n)
	{
		top = *a;
		if (top->index <= i)
		{
			pb(a, b);
			i++;
		}
		else if (top->index <= (i + range))
		{
			pb(a, b);
			r(b, 0);
			i++;
		}
		else
			r(a, 1);
	}
}

void	last_sort(t_stack **a, t_stack **b, int n)
{
	int		mid;
	t_stack	*top;
	t_stack	*big_node;

	top = *b;
	mid = n / 2;
	new_pos(*b);
	while (*b)
	{
		big_node = biggest_index(*b);
		if (big_node->pos <= mid)
		{
			while (*b != big_node)
				r(b, 0);
		}
		else
		{
			while (*b != big_node)
				rev_r(b, 0);
		}
		mid = n / 2;
		n--;
		(pa(a, b), new_pos(*b));
	}
}

void	the_big_sort(t_stack **a, t_stack **b, int n)
{
	int	range;
	int	count;	

	if (n > 250)
		range = 38;
	else
		range = 13;
	index_init(*a);
	indexing_list(*a);
	if (n == 5)
	{
		new_pos(*a);
		sort_5(a, b);
		return ;
	}
	count = its_sorted_des(*a, n / 2);
	if (count > n / 3 && n <= 100)
	{
		sort_the_des_list(a, b, n, 13);
		last_sort(a, b, n);
		return ;
	}
	sort_the_list(a, b, n, range);
	last_sort(a, b, n);
}
