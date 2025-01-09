/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhourba <zkhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:43:31 by zkhourba          #+#    #+#             */
/*   Updated: 2025/01/09 18:31:17 by zkhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static size_t	line_len(char *buffer)
{
	size_t	i;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	return (i);
}

static char	*get_line(char **data_saver)
{
	size_t	len;
	char	*line;
	char	*tmp;
	size_t	size;

	if (**data_saver == '\0')
	{
		free(*data_saver);
		*data_saver = NULL;
		return (NULL);
	}
	len = line_len(*data_saver);
	line = ft_substr(*data_saver, 0, len + 1);
	if (!line)
		return (free(*data_saver), *data_saver = NULL, NULL);
	tmp = *data_saver;
	size = ft_strlen(*data_saver);
	*data_saver = ft_substr(tmp, len + 1, size - len - 1);
	free(tmp);
	if (!*data_saver)
		return (free(line), NULL);
	return (line);
}

static int	saving_data(char **data_saver, char *buffer, int k)
{
	char	*tmp;

	if (k == -1)
	{
		if (*data_saver)
			free(*data_saver);
		return (*data_saver = NULL, 0);
	}
	buffer[k] = '\0';
	if (!*data_saver && *buffer != '\0')
	{
		*data_saver = ft_substr(buffer, 0, BUFFER_SIZE);
		if (!*data_saver)
			return (0);
		return (1);
	}
	else if (*buffer != '\0' && *data_saver)
	{
		tmp = *data_saver;
		*data_saver = ft_strjoin(tmp, buffer);
		if (!*data_saver)
			return (free(tmp), 0);
		return (free(tmp), 1);
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*data_saver = NULL;
	char		*buffer;
	int			k;

	if (fd < 0 || read(fd, NULL, 0) == -1 || BUFFER_SIZE == 0)
	{
		if (data_saver)
			return (free(data_saver), data_saver = NULL, NULL);
	}
	while (1)
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
		{
			if (data_saver)
				free(data_saver);
			return (NULL);
		}
		k = read(fd, buffer, BUFFER_SIZE);
		if (!saving_data(&data_saver, buffer, k) || (k == 0 && !data_saver))
			return (free(buffer), buffer = NULL, NULL);
		free(buffer);
		if (ft_strchr(data_saver, '\n') != NULL || (k == 0))
			return (get_line(&data_saver));
	}
}
