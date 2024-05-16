/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorcha-m <aorcha-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 19:17:02 by agu               #+#    #+#             */
/*   Updated: 2023/12/04 19:52:37 by aorcha-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Allocates memory (with malloc(3)) and returns an array of strings
 * obtained by splitting 's' with the character 'c' used as a delimiter.
 * The array must end with NULL. */

#include "libft.h"

static size_t	count_tokens(const char *s, char c)
{
	size_t	counter;

	counter = 0;
	while (*s && *s == c)
		s++;
	while (*s)
	{
		counter++;
		while (*s && *s != c)
			s++;
		while (*s && *s == c)
			s++;
	}
	return (counter);
}

static char	*copy_token(const char *s, int start, int end)
{
	char	*token;
	int		i;

	token = malloc(sizeof(char) * (end - start + 1));
	if (!token)
		return (NULL);
	i = -1;
	while (++i < (end - start))
		token[i] = s[start + i];
	token[i] = 0;
	return (token);
}

static char	**free_memory(char **tokens)
{
	int	i;

	i = -1;
	while (tokens[++i])
		free(tokens[i]);
	free(tokens);
	return (NULL);
}

static void	skip_first_delimiter(const char *s, char c, int *i, int *start)
{
	*i = 0;
	while (s[*i] && s[*i] == c)
		(*i)++;
	*start = *i;
	*i -= 1;
}

char	**ft_split(const char *s, char c)
{
	char	**array_token;
	int		i;
	int		token_index;
	int		token_start;

	array_token = malloc(sizeof(char *) * (count_tokens(s, c) + 1));
	if (!array_token)
		return (NULL);
	token_index = 0;
	skip_first_delimiter(s, c, &i, &token_start);
	while (s[++i])
	{
		if (s[i + 1] == c || !s[i + 1])
		{
			array_token[token_index] = copy_token(s, token_start, i + 1);
			if (!array_token[token_index++])
				return (free_memory(array_token));
			while (s[i + 1] && s[i + 1] == c)
				token_start = ++i + 1;
		}
	}
	array_token[token_index] = NULL;
	return (array_token);
}
