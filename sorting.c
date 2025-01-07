/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhourba <zkhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:21:57 by zkhourba          #+#    #+#             */
/*   Updated: 2025/01/07 18:50:16 by zkhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack **a,int n)
{
	t_stack	*f;
	t_stack	*sc;

	if(n == 1)
		return;

	f = *a;
	sc = f->next;
	if(sc->number < f->number)
		s(a,1);
	return;
}
void mini_sort(t_stack **a,t_stack **b,int n)
{
	t_stack	*f;
	t_stack	*sc;
	t_stack	*t;

	if(n < 3)
		return (sort_two(a,n));
	f = *a;
	sc = f->next;
	t = sc->next;
	if(sc->number > t->number && f->number < t->number)
		(pb(a,b),s(a,1),pa(a,b));
	if(f->number < sc->number && sc->number > t->number)
		rev_r(a,1);
	if(f->number > sc->number && f->number < t->number)
		s(a,1);
	if((f->number > sc->number ) && (f->number > t->number)
		 && sc->number < t->number)
		r(a,1);
	if((f->number > sc->number ) && (f->number > t->number)
		 && sc->number > t->number)
		 (r(a,1) , s(a,1));
}
void	index_init(t_stack *top)
{
	while (top)
	{
		top->index = 0;
		top = top->next;
	}
	
}
#include <stdio.h>

void	indexing_num(t_stack *num,t_stack *top)
{
	while (top)
	{
		if(num->number > top->number)
			num->index++;
		top =top->next;
	}
}
void	indexing_list(t_stack *top)
{
	t_stack *ptr1;
	t_stack	*ptr2;

	ptr1 = top;
	while (ptr1)
	{
		indexing_num(ptr1,top);
		ptr1 = ptr1->next;
	}
}
void sort_the_list(t_stack **a,t_stack **b,int n,int range)
{
	t_stack *top;
	int		i;

	i = 0;
	top = *a;
	while (n)
	{
		if(top->index <= i)
		{
			pb(a,b);
			ft_putstr_fd("here1\n",2);
			i++;
		}
		else if(top->index <= (i+ range))
		{
			pb(a,b);
			// r(b,0);
			i++;
			ft_putstr_fd("here2\n",2);
		}
		else
			r(a,1);
		top = top->next;
		n--;
	}
	
}
void	the_big_sort(t_stack **a,t_stack **b,int n)
{
	int range;
	
	if(n >= 100)
		range = 36;
	else
		range = 16;
	
	index_init(*a);
	indexing_list(*a);
	sort_the_list(a,b,n,range);
}