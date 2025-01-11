/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheker_utlis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhourba <zkhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 16:19:26 by zkhourba          #+#    #+#             */
/*   Updated: 2025/01/11 16:45:37 by zkhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	op(t_stack **a, t_stack **b, char *line)
{
	if (ft_strncmp(line, "pa\n", 4) == 0)
		return (pa(a, b, -1), 1);
	else if (ft_strncmp(line, "pb\n", 4) == 0)
		return (pb(a, b, -1), 1);
	else if (ft_strncmp(line, "sa\n", 4) == 0)
		return (s(a, -1), 1);
	else if (ft_strncmp(line, "sb\n", 4) == 0)
		return (s(b, -1), 1);
	else if (ft_strncmp(line, "ss\n", 4) == 0)
		return (ss(a, b), 1);
	else if (ft_strncmp(line, "ra\n", 4) == 0)
		return (r(a, -1), 1);
	else if (ft_strncmp(line, "rb\n", 4) == 0)
		return (r(b, -1), 1);
	else if (ft_strncmp(line, "rr\n", 4) == 0)
		return (rr(a, b), 1);
	else if (ft_strncmp(line, "rra\n", 5) == 0)
		return (rev_r(a, -1), 1);
	else if (ft_strncmp(line, "rrb\n", 5) == 0)
		return (rev_r(b, -1), 1);
	else if (ft_strncmp(line, "rrr\n", 5) == 0)
		return (rrr(a, b), 1);
	else
		return (0);
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
