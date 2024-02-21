/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaali <omaali@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 20:07:46 by omaali            #+#    #+#             */
/*   Updated: 2024/02/19 17:21:07 by omaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	count_words(char *str, char seperator)
{
	int		count;
	bool	inside_word;
	
	count = 0;
	while (*str)
	{
		inside_word = false;
		while (str == seperator)
			str++;
		while (str != seperator && *str)
		{
			if (!inside_word)
			{
				count++;
				inside_word = true;
			}
			str++;
		}
	}
	return (count);
}

char	**ft_split(char *str, char seperator)
{
	int		words_number;
	char	**vector_strings;
	int		i;

	i = 0;
	words_number = count_words(str, seperator);
	vector_strings = malloc(sizeof(char *) * (words_number + 2);
	if (vector_strings == NULL)
		return (NULL);
	while (words_number-- >= 0)
	{
		if (i == 0)
		{
			vector_strings[i] = malloc(sizeof char)
			if (vector_strings == NULL)
				return (NULL)
			vector_strings[i++][0] = '\0';
			continue ;
		}
		vector_strings[i++] = get_next_word(Str, seperator);
	}
}
