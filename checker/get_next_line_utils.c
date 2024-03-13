/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaali <omaali@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:13:23 by omaali            #+#    #+#             */
/*   Updated: 2024/01/18 02:22:50 by omaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	size_src;
	size_t	count;
	char	*sub;

	if (!s)
		return (NULL);
	count = 0;
	size_src = ft_strlen(s);
	if (start > size_src)
		sub = malloc(sizeof(char) * 1);
	else if (size_src - start < len)
		sub = malloc(sizeof(char) * (size_src - start + 1));
	else
		sub = malloc(sizeof(char) * (len + 1));
	if (sub == NULL)
		return (NULL);
	while (start + count < size_src && count < len)
	{
		sub[count] = s[start + count];
		count++;
	}
	sub[count] = '\0';
	return (sub);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;
	int		len;

	i = 0;
	s2 = NULL;
	len = ft_strlen(s1);
	while (i < len)
	{
		s2[i] = s1[i];
		i++;
	}
	return (s2);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	size;

	i = 0;
	size = ft_strlen(s) + 1;
	while (i < size)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*combo;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1)
	{
		s1 = malloc(1 * sizeof(char));
		if (!s1)
			return (free_str(&s1));
		s1[0] = '\0';
	}
	combo = (char *)malloc (ft_strlen(s1) + (ft_strlen(s2) + 1) * sizeof(char));
	if (combo == NULL)
		return (free_str(&s1));
	while (s1[i])
		combo[i++] = s1[j++];
	j = 0;
	while (s2[j])
		combo[i++] = s2[j++];
	combo[i] = '\0';
	free(s1);
	return (combo);
}
