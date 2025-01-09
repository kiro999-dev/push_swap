/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhourba <zkhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:14:42 by zkhourba          #+#    #+#             */
/*   Updated: 2025/01/09 18:25:55 by zkhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		write(fd,&s[i],1);
		i++;
	}
}
