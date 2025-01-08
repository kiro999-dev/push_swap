/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhourba <zkhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:21:57 by zkhourba          #+#    #+#             */
/*   Updated: 2025/01/08 07:20:24 by zkhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <math.h>
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

	if(n < 3)
		return (sort_two(a,n));
	if((*a)->number > (*a)->next->number && (*a)->number >(*a)->next->next->number)
		r(a,1);
	if((*a)->number < (*a)->next->number && (*a)->next->number >(*a)->next->next->number)
		rev_r(a,1);
	if((*a)->number > (*a)->next->number)
		s(a,1);
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
int its_sorted_des(t_stack *a, int n)
{
    t_stack *current;
    int i;
	int count;

	count = 0;
    if (!a || n <= 1) 
        return (1);

    current = a;
	i = 0;
   while (i < n -1)
   {
        if (current->number < current->next->number)
            count--; 
        current = current->next;
		count++;
		i++;
    }
    return (count); 
}


void sort_the_des_list(t_stack **a,t_stack **b,int n,int range)
{
	t_stack *top;
	int		i;

	i = 0;

	while (i < n)
	{
		top = *a;
		if(top->index <= i)
		{
			pb(a,b);
			i++;
		}
		else if(top->index <= (i + range))
		{
			pb(a,b);
			r(b,0);
			i++;
		}
		else
			rev_r(a,1);
	}
}
void sort_the_list(t_stack **a,t_stack **b,int n,int range)
{
	t_stack *top;
	t_stack	*last;
	
	int		i;

	i = 0;

	while (i < n)
	{
		top = *a;
		if(top->index <= i)
		{
			pb(a,b);
			i++;
		}
		else if(top->index <= (i + range))
		{
			pb(a,b);
			r(b,0);
			i++;
		}
		else
			r(a,1);
	}
}
t_stack *biggest_index(t_stack *b)
{
	int max;
	t_stack *biggest;
	max = INT_MIN;
	
	while (b)
	{
		if(max <= b->index)
		{
			max = b->index;
			biggest = b;
		}
		b = b->next;
	}
	return (biggest);
}
void new_pos(t_stack *b)
{
	int i;

	i = 0;
	while (b)
	{
		b->pos = i;
		i++;
		b = b->next;
	}
}
void	last_sort(t_stack **a,t_stack **b,int n)
{
	int	mid;
	int	i;
	t_stack *top;
	t_stack *big_node;
	
	top = *b;
	mid = n / 2;
	new_pos(*b);
	while (*b)
	{
		big_node =  biggest_index(*b);
		
		if(big_node->pos <= mid)
		{
			while (*b != big_node)
				r(b,0);	
		}
		else
		{
			while (*b != big_node)
				rev_r(b,0);
		}
		mid = n / 2;
		n--;
		pa(a,b);
		new_pos(*b);
	}
}
void	the_big_sort(t_stack **a,t_stack **b,int n)
{
	int range;
	int count;	

	if(n > 100)
		range = 36;
	else
		range = 13;
		
	index_init(*a);
	indexing_list(*a);
	count = its_sorted_des(*a,n/2);
	if(count > n / 3 && n <= 100)
	{
		sort_the_des_list(a,b,n,13);
		last_sort(a,b,n);
			return;
	}
	sort_the_list(a,b,n,range);
	last_sort(a,b,n);
}
