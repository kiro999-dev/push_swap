/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_op_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhourba <zkhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:24:22 by zkhourba          #+#    #+#             */
/*   Updated: 2025/01/14 16:02:18 by zkhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s(t_stack **stack, int flag)
{
	t_stack	*elm1;
	t_stack	*elm2;

	if (stack == NULL)
		return ;
	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	if (flag)
		ft_putstr_fd("sa\n", 1);
	else
		ft_putstr_fd("sb\n", 1);
	elm1 = (*stack);
	elm2 = (*stack)->next;
	elm1->next = elm2->next;
	elm2->next = elm1;
	*stack = elm2;
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*top_elm_b;

	if (stack_b == NULL || stack_a == NULL)
		return ;
	if (*stack_b == NULL)
		return ;
	ft_putstr_fd("pa\n", 1);
	top_elm_b = *stack_b;
	*stack_b = (*stack_b)->next;
	top_elm_b->next = *stack_a;
	*stack_a = top_elm_b;
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*top_elm_a;

	if (stack_b == NULL || stack_a == NULL)
		return ;
	if (*stack_a == NULL)
		return ;
	ft_putstr_fd("pb\n", 1);
	top_elm_a = *stack_a;
	*stack_a = (*stack_a)->next;
	top_elm_a->next = *stack_b;
	*stack_b = top_elm_a;
}
