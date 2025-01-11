/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_list_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhourba <zkhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 16:47:18 by zkhourba          #+#    #+#             */
/*   Updated: 2025/01/11 16:49:36 by zkhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

t_stack	*ft_last(t_stack *stack)
{
	if (stack == NULL)
		return (stack);
	while (stack->next)
	{
		stack = stack->next;
	}
	return (stack);
}

t_list	*ft_last_list(t_list *stack)
{
	if (stack == NULL)
		return (stack);
	while (stack->next)
	{
		stack = stack->next;
	}
	return (stack);
}

int	list_len(t_stack *stack)
{
	int	n;

	n = 0;
	while (stack)
	{
		stack = stack->next;
		n++;
	}
	return (n);
}
