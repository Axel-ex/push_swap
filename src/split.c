/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 11:41:32 by achabrer          #+#    #+#             */
/*   Updated: 2023/09/11 11:54:57y achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int	count_words(char *s, char sep)
{
	bool	inside_word;
	int		count;

	inside_word = false;
	count = 0;
	while (*s)
	{
		if (!inside_word && *s != sep)
		{
			count++;
			inside_word = true;

		}
		else if (*s == sep)
			inside_word = false;
		s++;
	}
	return (count);
}

static int	strlen_next(char *s, char sep)
{
	int	i;

	i = 0;
	while (*s && *s != sep)
	{
		i++;
		s++;
	}
	return (i);
}

static char	*get_next_word(char *s, char sep)
{
	char	*dup;
	char	*origin;

	dup = (char *) malloc(sizeof(char) * (strlen_next(s, sep)) + 1);
	if (!dup)
		return (NULL);
	origin = dup;
	while (*s && *s != sep)
		*dup++ = *s++;
	*dup = '\0';
	return (origin);
}

char	**split(char *s, char sep)
{
	char	**split;
	int		i;

	split = (char **)malloc(sizeof(char *) * (count_words(s, sep) + 2));
	if (!split)
		return (NULL);
	i = 0;
	split[++i] = NULL;
	while (*s)
	{
		while (*s && *s == sep)
			s++;
		split[i] = get_next_word(s, sep);
		i++;
		while (*s && *s != sep)
			s++;
	}
	split[i] = NULL;
	return (split);
}