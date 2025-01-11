/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_list_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhourba <zkhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 18:21:18 by zkhourba          #+#    #+#             */
/*   Updated: 2025/01/11 16:49:16 by zkhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

t_stack	*creat_node(int num, int pos)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (node == NULL)
		return (NULL);
	node->next = NULL;
	node->number = num;
	node->pos = pos;
	return (node);
}

t_list	*creat_node_list(char *line)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node->line = line;
	node->next = NULL;
	return (node);
}

void	add_to_list(t_list **head, char *line)
{
	t_list	*node;
	t_list	*tmp;

	node = creat_node_list(line);
	if (head == NULL)
		return ;
	if (*head == NULL)
	{
		*head = node;
		return ;
	}
	tmp = ft_last_list(*head);
	tmp->next = node;
}

void	add_to_stack(t_stack **head, int num, int pos)
{
	t_stack	*node;
	t_stack	*tmp;

	node = creat_node(num, pos);
	if (head == NULL)
		return ;
	if (*head == NULL)
	{
		*head = node;
		return ;
	}
	tmp = ft_last(*head);
	tmp->next = node;
}
