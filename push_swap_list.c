/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhourba <zkhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:14:13 by zkhourba          #+#    #+#             */
/*   Updated: 2025/01/07 18:39:58 by zkhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *creat_node(int num,int pos)
{
	t_stack *node;
	
	node = malloc(sizeof(t_stack));
	
	if(node == NULL)
		return (NULL);
		
	node->next = NULL;
	node->number = num;
	node->pos = pos;
	return(node);
	
}
void add_to_stack(t_stack **head,int num,int pos)
{
	t_stack *node;
	 
	if(head == NULL)
		return ;
	node = creat_node(num,pos);
	node->next = *head;
	*head = node;  
}
t_stack *ft_last(t_stack *stack)
{
	if(stack == NULL)
		return(stack);
	while (stack->next)
	{
		stack = stack->next;
	}
	return (stack);
}
int list_len(t_stack *stack)
{
	int n;

	n = 0;
	while (stack)
	{
		stack= stack->next;
		n++;
	}
	return (n);
}
