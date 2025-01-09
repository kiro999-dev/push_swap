/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhourba <zkhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:10:16 by zkhourba          #+#    #+#             */
/*   Updated: 2025/01/09 17:03:41 by zkhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
int check_dup(t_stack *head, int num)
{
	if (head == NULL)
		return (0);
	while (head)
	{
		if(head->number == num)
			return (1);
		head = head->next;
	}
	return (0);
}

void check_table(char **table, t_stack **head)
{	
	int 		i;
	long long 	num;
	int			flag;
	
	
	if(table == NULL)
		ft_putstr_fd("fail in malloc",2),exit(1);
	if(table[0] == NULL)
		(ft_putstr_fd("Error\n",2),free(table),exit(1));
	i = 0;
	num = 0;
	while (table[i])
	{
		num = ft_atoi(table[i],&flag);
		if(num > INT_MAX || flag || check_dup(*head,num))
		{
			free_stack(head);
			(ft_putstr_fd("Error\n",2),ft_free(table),exit(1));
		}
		add_to_stack(head,num,i);
		i++;
	}
}

void	pars_arg(char *arg, t_stack **head)
{
	int	i;
	char **table;
	
	i = 0;
	table = ft_split(arg,' ');
	check_table(table,head);
	ft_free(table);
}

void	parsing(char **argv, t_stack **head)
{
	int	i;
	
	i = 1;
	while (argv[i])
	{
		pars_arg(argv[i], head);
		i++;
	}
}