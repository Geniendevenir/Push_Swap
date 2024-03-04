/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebert <adebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:07:06 by adebert           #+#    #+#             */
/*   Updated: 2024/02/21 17:56:55 by adebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split(char const *s, char c);

int	sep_count(char *str, char sep)
{
	if (*str == sep)
		return (1);
	return (0);
}

int	ft_words(char *str, char sep)
{
	int		i;
	int		words;

	words = 0;
	i = 0;
	if (sep == 32 && ft_strlen(str) == 0)
		return (0);
	if (sep_count(&str[0], sep) == 0)
		words++;
	while (str[i])
	{
		if (sep_count(&str[i], sep))
		{
			if (str[i + 1] && sep_count(&str[i + 1], sep) == 0)
				words++;
		}
		i++;
	}
	return (words);
}

void	ft_free(char**split)
{
	size_t	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

char	*ft_strdup_split(char *str, char c, char **split)
{
	char	*new;
	int		i;
	int		len;

	len = 0;
	while (str[len] && sep_count(&str[len], c) == 0)
		len++;
	i = 0;
	new = malloc(sizeof(char) * (len + 1));
	if (!new)
	{
		ft_free (split);
		return (NULL);
	}
	while (i < len)
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		words;
	char	*str;
	char	**split;

	str = (char *)s;
	i = 0;
	words = ft_words(str, c);
	split = malloc(sizeof(char *) * (words + 1));
	if (!split)
		return (0);
	while (*str)
	{
		while (sep_count(str, c) && *str)
			str++;
		if (*str)
		{
			split[i] = ft_strdup_split(str, c, split);
			i++;
		}
		while (sep_count(str, c) == 0 && *str)
			str++;
	}
	split[i] = 0;
	return (split);
}
