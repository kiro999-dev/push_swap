/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_list_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhourba <zkhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:14:13 by zkhourba          #+#    #+#             */
/*   Updated: 2025/01/09 18:25:40 by zkhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
	t_stack *tmp;
	
	node = creat_node(num,pos);
	if(head == NULL)
		return ;
	if(*head == NULL)
	{
		*head =node;
		return;
	}
	tmp = ft_last(*head);
	tmp->next = node;
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
