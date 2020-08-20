/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwiley <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 10:20:27 by fwiley            #+#    #+#             */
/*   Updated: 2019/09/24 11:24:51 by fwiley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_n_word(char const *str, char space)
{
	size_t	n_words;

	n_words = 0;
	while (*str)
	{
		if (*str != space)
			n_words++;
		if (!(str = ft_strchr(str, space)))
			return (n_words);
		while (*str == space && *str)
			str++;
	}
	return (n_words);
}

static char		*ft_get_word(const char *str, char space)
{
	char	*word;
	size_t	size;

	size = 0;
	while (*str == space && *str)
		str++;
	while (*str != space && *str)
	{
		size++;
		str++;
	}
	if ((word = ft_strnew(size)))
		ft_strncpy(word, (char *)(str - size), size);
	return (word);
}

static void		ft_free(char **words, size_t size)
{
	while (size--)
		ft_strdel(&words[size]);
	free(words);
}

static char		**ft_get_words(const char *str, char space)
{
	char	**words;
	size_t	n_words;
	size_t	i;

	n_words = ft_n_word(str, space);
	if ((words = (char **)ft_memalloc(sizeof(char *) * (n_words + 1))))
	{
		i = 0;
		while (*str)
		{
			while (*str == space && *str)
				str++;
			if (*str)
			{
				if (!(words[i] = ft_get_word(str, space)))
				{
					ft_free(words, i);
					return (NULL);
				}
				str += ft_strlen(words[i++]);
			}
		}
		words[i] = NULL;
	}
	return (words);
}

char			**ft_strsplit(const char *s, char c)
{
	if (!s || !c)
		return (NULL);
	return (ft_get_words(s, c));
}
