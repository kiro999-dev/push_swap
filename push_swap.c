/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhourba <zkhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 19:35:20 by zkhourba          #+#    #+#             */
/*   Updated: 2025/01/07 18:47:57 by zkhourba         ###   ########.fr       */
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
	// else
		the_big_sort(&stack_a,&stack_b,n);
	// while ((stack_a))
	// {
	// 	printf("a:%d--->%d\n",stack_a->number,stack_a->index);
	// 	stack_a =stack_a->next;
	// }
	return (0);
}
