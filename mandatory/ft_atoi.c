/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhourba <zkhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:31:40 by zkhourba          #+#    #+#             */
/*   Updated: 2025/01/12 18:40:04 by zkhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	itssapce(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

static int	skip(const char *s)
{
	int	i;

	i = 0;
	while (s[i] && itssapce(s[i]))
		i++;
	return (i);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	signe(const char *str, int i, int *ptr_flag, int *ptr_flag2)
{
	*ptr_flag2 = 0;
	if (str[i] == '-')
	{
		*ptr_flag = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	return (i);
}

long long	ft_atoi(const char *str, int *flagerr)
{
	int			i;
	int			flag;
	long long	res;
	int			flag2;

	i = skip(str);
	res = 0;
	flag = 1;
	*flagerr = 0;
	i = signe(str, i, &flag, &flag2);
	while (ft_isdigit(str[i]))
	{
		if (res > ((9223372036854775807 - (str[i] - '0')) / 10) && flag == -1)
			return (*flagerr = 1, 0);
		else if (res > ((9223372036854775807 - (str[i] - '0')) / 10) && flag)
			return (*flagerr = 1, -1);
		res = res * 10 + (str[i] - '0');
		i++;
		flag2 = 1;
	}
	if (str[i] != '\0')
		*flagerr = 1;
	if (str[i] == '\0' && flag2 == 0)
		*flagerr = 1;
	return (res * flag);
}
