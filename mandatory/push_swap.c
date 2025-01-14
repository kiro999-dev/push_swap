/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhourba <zkhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 19:35:20 by zkhourba          #+#    #+#             */
/*   Updated: 2025/01/12 19:38:58 by zkhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_4(t_stack **a, t_stack **b)
{
	t_stack	*smallest;

	smallest = smallest_index(*a);
	new_pos(*a);
	index_init(*a);
	indexing_list(*a);
	while (*a != smallest)
	{
		if (smallest->pos <= 2)
			r(a, 1);
		else
			rev_r(a, 1);
	}
	pb(a, b);
	mini_sort(a, 3);
	pa(a, b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		n;

	if (argc == 1)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	parsing(argv, &stack_a);
	if (its_sorted(stack_a))
		return (free_stack(&stack_a), 0);
	n = list_len(stack_a);
	if (n <= 3)
		mini_sort(&stack_a, n);
	else if (n == 4)
		sort_4(&stack_a, &stack_b);
	else
		the_big_sort(&stack_a, &stack_b, n);
	free_stack(&stack_a);
	return (0);
}
