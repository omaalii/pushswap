/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaali <omaali@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 08:28:54 by omaali            #+#    #+#             */
/*   Updated: 2024/01/18 00:24:31 by omaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	*free_str(char **str)
{
	free(*str);
	(*str) = NULL;
	return (NULL);
}

char	*ft_update_storage(char *storage)
{
	int		len;
	int		i;
	char	*new_storage;

	if (!storage)
		return (NULL);
	i = 0;
	while (storage[i] != '\0' && storage[i] != '\n')
		i++;
	if (storage[i] == '\0')
	{
		free(storage);
		return (NULL);
	}
	i++;
	len = ft_strlen(storage) - i;
	new_storage = ft_substr(storage, i, len);
	free(storage);
	return (new_storage);
}

char	*ft_line(char *storage)
{
	char	*result;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!storage || storage[0] == '\0')
		return (NULL);
	while (storage[i] != '\0' && storage[i] != '\n')
		i++;
	if (storage[i] == '\n')
		i++;
	result = (char *)malloc (i + 1 * sizeof(char));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (storage[i] != '\0' && storage[i] != '\n')
		result[i++] = storage[j++];
	if (storage[i] == '\n')
		result[i++] = storage[j++];
	result[i] = '\0';
	return (result);
}

char	*ft_read(char *storage, int fd)
{
	char	*buffer;
	int		b_read;

	buffer = NULL;
	b_read = 1;
	buffer = (char *)malloc(sizeof (char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (free_str(&storage));
	buffer[0] = '\0';
	while (b_read > 0 && !ft_strchr(buffer, '\n'))
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		if (b_read == -1)
		{
			free(buffer);
			return (free_str(&storage));
		}
		buffer[b_read] = '\0';
		storage = ft_strjoin(storage, buffer);
	}
	free(buffer);
	return (storage);
}

char	*get_next_line(int fd)
{
	static char	*storage = NULL;
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	storage = ft_read(storage, fd);
	if (!storage)
		return (NULL);
	line = ft_line(storage);
	if (!line)
	{
		free_str(&storage);
		return (NULL);
	}
	storage = ft_update_storage(storage);
	return (line);
}
