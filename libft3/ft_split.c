/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjullien <kjullien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:22:16 by kjullien          #+#    #+#             */
/*   Updated: 2024/11/14 23:37:15 by kjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

static int	ft_is_separator(char to_test, char separator)
{
	if (to_test == separator)
		return (1);
	return (0);
}

static size_t	ft_count_words(const char *s, char c)
{
	int		is_word;
	size_t	word_counter;
	size_t	counter;

	is_word = 0;
	word_counter = 0;
	counter = 0;
	while (s[counter])
	{
		if (ft_is_separator(s[counter], c))
			is_word = 0;
		else if (!is_word)
		{
			word_counter++;
			is_word = 1;
		}
		counter++;
	}
	return (word_counter);
}

static void	*ft_free_words(char **r, size_t total_word_counter)
{
	while (total_word_counter > 0)
	{
		free(r[total_word_counter - 1]);
		total_word_counter--;
	}
	free(r);
	return (NULL);
}

static int	ft_next_word(const char *s, char c, size_t *index, char **word)
{
	size_t	counter;
	size_t	start;
	size_t	end;

	while (s[*index] && ft_is_separator(s[*index], c))
		(*index)++;
	start = *index;
	while (s[*index] && !ft_is_separator(s[*index], c))
		(*index)++;
	end = *index;
	if (start == end)
		return (0);
	*word = malloc((end - start + 1) * sizeof(char));
	if (!*word)
		return (-1);
	counter = 0;
	while (counter < end - start)
	{
		(*word)[counter] = s[start + counter];
		counter++;
	}
	(*word)[counter] = 0;
	return (1);
}

char			**ft_split(char const *s, char c);

char	**ft_split(char const *s, char c)
{
	char	**splitted;
	size_t	counter;
	size_t	index;
	char	*word;
	int		next_result;

	splitted = malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (!splitted)
		return (NULL);
	counter = 0;
	if (ft_count_words(s, c))
	{
		index = 0;
		while (s[index])
		{
			next_result = ft_next_word(s, c, &index, &word);
			if (next_result == 1)
				splitted[counter++] = word;
			else if (next_result == -1)
				return (ft_free_words(splitted, counter));
		}
	}
	splitted[ft_count_words(s, c)] = 0;
	return (splitted);
}
