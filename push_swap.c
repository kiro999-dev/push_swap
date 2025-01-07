/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhourba <zkhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 19:35:20 by zkhourba          #+#    #+#             */
/*   Updated: 2025/01/07 16:17:14 by zkhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

//makefile 
int main(int argc , char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	
	if (argc == 1)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	parsing(argv,&stack_a);
	while ((stack_a))
	{
		printf("a:%d\n",stack_a->number);
		stack_a =stack_a->next;
	}
	return (0);
}
