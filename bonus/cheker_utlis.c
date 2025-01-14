/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheker_utlis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhourba <zkhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 16:19:26 by zkhourba          #+#    #+#             */
/*   Updated: 2025/01/12 15:14:53 by zkhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	op(t_stack **a, t_stack **b, char *line)
{
	if (ft_strncmp(line, "pa\n", 4) == 0)
		pa(a, b, -1);
	else if (ft_strncmp(line, "pb\n", 4) == 0)
		pb(a, b, -1);
	else if (ft_strncmp(line, "sa\n", 4) == 0)
		s(a, -1);
	else if (ft_strncmp(line, "sb\n", 4) == 0)
		s(b, -1);
	else if (ft_strncmp(line, "ss\n", 4) == 0)
		ss(a, b);
	else if (ft_strncmp(line, "ra\n", 4) == 0)
		r(a, -1);
	else if (ft_strncmp(line, "rb\n", 4) == 0)
		r(b, -1);
	else if (ft_strncmp(line, "rr\n", 4) == 0)
		rr(a, b);
	else if (ft_strncmp(line, "rra\n", 5) == 0)
		rev_r(a, -1);
	else if (ft_strncmp(line, "rrb\n", 5) == 0)
		rev_r(b, -1);
	else if (ft_strncmp(line, "rrr\n", 5) == 0)
		rrr(a, b);
	else
		return ;
}

int	op_check(char *line)
{
	if (ft_strncmp(line, "pa\n", 4) == 0)
		return (1);
	else if (ft_strncmp(line, "pb\n", 4) == 0)
		return (1);
	else if (ft_strncmp(line, "sa\n", 4) == 0)
		return (1);
	else if (ft_strncmp(line, "sb\n", 4) == 0)
		return (1);
	else if (ft_strncmp(line, "ss\n", 4) == 0)
		return (1);
	else if (ft_strncmp(line, "ra\n", 4) == 0)
		return (1);
	else if (ft_strncmp(line, "rb\n", 4) == 0)
		return (1);
	else if (ft_strncmp(line, "rr\n", 4) == 0)
		return (1);
	else if (ft_strncmp(line, "rra\n", 5) == 0)
		return (1);
	else if (ft_strncmp(line, "rrb\n", 5) == 0)
		return (1);
	else if (ft_strncmp(line, "rrr\n", 5) == 0)
		return (1);
	else
		return (0);
}
