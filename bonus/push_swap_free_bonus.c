/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_free_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhourba <zkhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:07:29 by zkhourba          #+#    #+#             */
/*   Updated: 2025/01/10 17:20:31 by zkhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ft_free(char **ptr)
{
	int	i;

	i = 0;
	if (ptr == NULL)
		return ;
	while (ptr[i])
	{
		free(ptr[i]);
		ptr[i] = NULL;
		i++;
	}
	free(ptr);
	ptr = NULL;
}

void	free_stack(t_stack **head)
{
	t_stack	*tmp;

	if (head == NULL)
		return ;
	if (*head == NULL)
		return ;
	tmp = *head;
	while (tmp)
	{
		tmp = (*head)->next;
		free(*head);
		*head = tmp;
	}
}
