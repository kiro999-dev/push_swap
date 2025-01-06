/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhourba <zkhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 19:35:20 by zkhourba          #+#    #+#             */
/*   Updated: 2025/01/06 12:32:53 by zkhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void check_table(char **table)
{	
	int i;
	long long num;
	if(table == NULL)
		ft_putstr_fd("fail in malloc",2),exit(1);
	if(table[0] == NULL)
		(ft_putstr_fd("Error\n",2),free(table),exit(1));
	i = 0;
	while (table[i])
	{
		num = ft_atoi(table[i]);
		if(num > INT_MAX || check_num())
			(ft_putstr_fd("Error\n",2),ft_free(table),exit(1));
		printf("%lld\n",num);
		i++;
	}
}

void	pars_arg(char *arg)
{
	int	i;
	char **table;
	
	i = 0;
	table = ft_split(arg,' ');
	check_table(table);
	ft_free(table);
}
void	parsing(char **argv)
{

	int	i;
	i = 1;
	while (argv[i])
	{
		pars_arg(argv[i]);
		i++;
	}
}
int main(int argc , char **argv)
{
	if (argc == 1)
		return (0);
	parsing(argv);
	// add_to_satck();
}