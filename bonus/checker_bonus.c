/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhourba <zkhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 18:05:32 by zkhourba          #+#    #+#             */
/*   Updated: 2025/01/11 16:45:26 by zkhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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

void	exec_op(t_list *head, t_stack **a, t_stack **b)
{
	while (head && head->line)
	{
		if (op(a, b, head->line) == 0)
			(ft_putstr_fd("Error\n", 2), free_stack(a), free_stack(b), exit(1));
		head = head->next;
	}
}

void	read_and_exc(t_stack **a, t_stack **b)
{
	char	*line;
	t_list	*head;

	head = NULL;
	line = get_next_line(0);
	add_to_list(&head, line);
	if (op_check(head->line) == 0)
		(ft_putstr_fd("Error\n", 2), free_stack(a), free_stack(a), exit(1));
	while (line)
	{
		line = get_next_line(0);
		if (op_check(head->line) == 0)
			(ft_putstr_fd("Error\n", 2), free_stack(a), free_stack(a), exit(1));
		add_to_list(&head, line);
	}
	exec_op(head, a, b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 1)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	parsing(argv, &stack_a);
	read_and_exc(&stack_a, &stack_b);
	if (its_sorted(stack_a) == 1)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
