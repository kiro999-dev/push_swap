/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhourba <zkhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:54:05 by zkhourba          #+#    #+#             */
/*   Updated: 2025/01/09 18:31:24 by zkhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	i;

	sub_str = NULL;
	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		sub_str = malloc(1);
		sub_str[0] = '\0';
		return (sub_str);
	}
	if (len > ft_strlen(s))
		sub_str = (char *)malloc(ft_strlen(s + start) + 1);
	else
		sub_str = (char *) malloc(len + 1);
	if (!sub_str)
		return (NULL);
	while (i < len && s[start])
		sub_str[i++] = s[start++];
	sub_str[i] = '\0';
	return (sub_str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	len_res;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (0);
	len_res = ft_strlen(s1) + ft_strlen(s2) + 1;
	res = malloc(len_res);
	if (!res)
		return (NULL);
	while (s1[i] && i < len_res)
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		res[i++] = s2[j];
		j++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_strchr(const char *s, int c)
{
	char	*ptr_s;

	ptr_s = (char *) s;
	while (*ptr_s)
	{
		if (*ptr_s == (char) c)
			return (ptr_s);
		ptr_s++;
	}
	if (*ptr_s == (char)c)
		return (ptr_s);
	return (NULL);
}
