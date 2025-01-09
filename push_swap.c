/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhourba <zkhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 19:35:20 by zkhourba          #+#    #+#             */
/*   Updated: 2025/01/09 16:55:23 by zkhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int main(int argc , char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		n;
	if (argc == 1)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	parsing(argv,&stack_a);
	n = list_len(stack_a);
	if(n <= 3)
		mini_sort(&stack_a,&stack_b,n);
	else
		the_big_sort(&stack_a,&stack_b,n);
	
	free_stack(&stack_a);
	return (0);
}
