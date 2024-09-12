/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marias-e <marias-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 12:06:37 by davgonza          #+#    #+#             */
/*   Updated: 2023/03/14 11:44:14 by marias-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_getsplits(char const *s, char c)
{
	size_t	splits;
	int		i;

	splits = 0;
	i = 0;
	if (s)
	{
		while (s[i])
		{
			while (s[i] == c)
				i++;
			while (s[i] != c && s[i])
				i++;
			if (s && s[i - 1] != c)
				splits++;
		}
	}
	return (splits);
}

static size_t	ft_split_size(char const *s, char c)
{
	size_t	size;

	size = 0;
	while (s[size] != c && s[size])
		size++;
	return (size);
}

static void	ft_clear(char **strs, int pos)
{
	pos++;
	while (--pos >= 0)
		free(strs[pos]);
	free(strs);
}

static int	ft_splitcpy(char const *s, char c, char **strs)
{
	int		n;
	int		i;
	size_t	size;

	n = 0;
	i = 0;
	while (s[n])
	{
		while (s[n] && s[n] == c)
			n++;
		if (!s[n])
			return (1);
		size = ft_split_size(&s[n], c);
		strs[i] = ft_substr(s, n, size);
		if (!strs[i])
		{
			ft_clear(strs, i - 1);
			return (0);
		}
		i++;
		n += size;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	size_t	splits;
	char	**strs;

	splits = ft_getsplits(s, c);
	if (!splits)
		return (ft_calloc(1, sizeof(char *)));
	strs = ft_malloc(sizeof(char *) * (splits + 1));
	if (!ft_splitcpy(s, c, strs))
		return (0);
	strs[splits] = 0;
	return (strs);
}
