/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhourba <zkhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:14:13 by zkhourba          #+#    #+#             */
/*   Updated: 2025/01/06 11:46:07 by zkhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *creat_node(int num)
{
    t_stack *node;
    
    node = malloc(sizeof(t_stack));
    
    if(node ==NULL)
        return (NULL);
        
    node->next = NULL;
    node->number = num;
    return(node);
    
}
void add_to_stack(t_stack **head,int num)
{
    t_stack *node;
     
    if(head ==NULL)
        return;
    node = creat_node(num);
    node->next = *head;
    *head = node;  
}

