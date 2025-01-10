/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhourba <zkhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:51:18 by zkhourba          #+#    #+#             */
/*   Updated: 2025/01/10 17:53:37 by zkhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack **a, int n)
{
	t_stack	*f;
	t_stack	*sc;

	if (n == 1)
		return ;
	f = *a;
	sc = f->next;
	if (sc->number < f->number)
		s(a, 1);
	return ;
}

void	mini_sort(t_stack **a, int n)
{
	if (n < 3)
		return (sort_two(a, n));
	if (((*a)->number > (*a)->next->number)
		&& ((*a)->number > (*a)->next->next->number))
		r(a, 1);
	if (((*a)->number < (*a)->next->number)
		&& (*a)->next->number > (*a)->next->next->number)
		rev_r(a, 1);
	if ((*a)->number > (*a)->next->number)
		s(a, 1);
}
