/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhourba <zkhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:17:18 by zkhourba          #+#    #+#             */
/*   Updated: 2025/01/06 10:41:17 by zkhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	*free_memory(char **res, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(res[i]);
		i++;
	}
	free(res);
	return (NULL);
}

static size_t	counting_words(const char *s1, char c)
{
	size_t	count;
	int		in_word;

	count = 0;
	in_word = 0;
	while (*s1)
	{
		if (*s1 == c)
			in_word = 0;
		else
		{
			if (!in_word)
			{
				count++;
				in_word = 1;
			}
		}
		s1++;
	}
	return (count);
}

static char	*fill(char *s, char c, int *ptr_i)
{
	size_t	len;
	char	*str;

	len = 0;
	while (s[*ptr_i + len] && s[*ptr_i + len] != c)
		len++;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	len = 0;
	while (s[*ptr_i] && s[*ptr_i] != c)
	{
		str[len] = s[*ptr_i];
		(*ptr_i)++;
		len++;
	}
	str[len] = '\0';
	return (str);
}

char	**ft_split(const char *s, char c)
{
	char	**res;
	int		k;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	k = 0;
	res = (char **) malloc(sizeof(char *) * (counting_words(s, c) + 1));
	if (!res)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			res[k] = fill((char *) s, c, &i);
			if (!res[k])
				return (free_memory(res, k));
			k++;
		}
		else
			i++;
	}
	res[k] = NULL;
	return (res);
}
