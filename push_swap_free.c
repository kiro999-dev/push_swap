/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhourba <zkhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:07:29 by zkhourba          #+#    #+#             */
/*   Updated: 2025/01/08 17:54:02 by zkhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "push_swap.h"

void ft_free(char **ptr)
{
    int i = 0;
    if(ptr == NULL)
        return;
    while (ptr[i])
    {
        free(ptr[i]);
        ptr[i] = NULL;
        i++;
    }
    ptr = NULL;
}
void free_stack(t_stack **head)
{
    t_stack *tmp;

    if (head == NULL)
        return ;
    if(*head == NULL)
        return;
    while (tmp)
    {
        tmp = (*head)->next;
        free(*head);
        *head = tmp;
    }
    
}