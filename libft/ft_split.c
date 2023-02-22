/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 11:31:11 by asarikha          #+#    #+#             */
/*   Updated: 2022/11/09 16:05:47 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(const char *s, char c)
{
	size_t	words;
	size_t	i;

	words = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if ((i == 0 || s[i - 1] == c) && s[i] != c)
			words++;
		i++;
	}
	return (words);
}

static size_t	ft_wordlen(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			s++;
			i++;
		}
		else
			return (i);
	}
	return (i);
}

static	char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;
	size_t	slen;

	i = 0;
	slen = ft_strlen(src);
	while (i < len)
	{
		if (i < slen)
			dst[i] = src[i];
		else
			dst[i] = '\0';
		i++;
	}
	return (dst);
}

static	char	**make_word_list(char const *s, size_t word_count,
		char	**word_list, char c)
{
	size_t	word_len;
	size_t	i;

	i = 0;
	while (i < word_count && word_list)
	{
		while (*s != '\0' && *s == c)
			s++;
		word_len = ft_wordlen(&*s, c);
		word_list[i] = malloc(sizeof(**word_list) * (word_len + 1));
		if (!word_list[i])
		{
			while (i-- > 0)
				free (word_list[i]);
			return (NULL);
		}
		ft_strncpy(word_list[i], &(*s), word_len);
		word_list[i][word_len] = '\0';
		while (*s != '\0' && *s != c)
			s++;
		i++;
	}
	word_list[i] = NULL;
	return (word_list);
}

char	**ft_split(char const *s, char c)
{
	char	**word_list;
	size_t	nb_words;

	if (!s)
		return (0);
	nb_words = ft_count_words(s, c);
	word_list = (char **)malloc(sizeof(char *) * (nb_words + 1));
	if (!(word_list))
	{
		free(word_list);
		return (NULL);
	}
	word_list = make_word_list(s, nb_words, word_list, c);
	return (word_list);
}
