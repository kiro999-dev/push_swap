/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_op_2_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhourba <zkhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 16:45:25 by zkhourba          #+#    #+#             */
/*   Updated: 2025/01/14 16:00:14 by zkhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	r(t_stack **stack, int flag)
{
	t_stack	*top;
	t_stack	*last;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	if (flag == 1)
		ft_putstr_fd("ra\n", 1);
	else if (flag == 0)
		ft_putstr_fd("rb\n", 1);
	top = *stack;
	*stack = (*stack)->next;
	top->next = NULL;
	last = ft_last(*stack);
	last->next = top;
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	r(stack_a, -1);
	r(stack_b, -1);
}

t_stack	*before_last(t_stack *stack)
{
	t_stack	*top;
	int		n;
	int		i;

	top = stack;
	n = list_len(stack);
	i = 0;
	while (i < n - 2)
	{
		top = top->next;
		i++;
	}
	return (top);
}

void	rev_r(t_stack **stack, int flag)
{
	t_stack	*last;
	t_stack	*bef_last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	if (*stack == NULL)
		return ;
	if (flag == 1)
		ft_putstr_fd("rra\n", 1);
	else if (flag == 0)
		ft_putstr_fd("rrb\n", 1);
	last = ft_last(*stack);
	bef_last = before_last(*stack);
	bef_last->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rev_r(stack_a, -1);
	rev_r(stack_b, -1);
}
