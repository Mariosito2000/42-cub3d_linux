/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marias-e <marias-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 10:16:19 by davgonza          #+#    #+#             */
/*   Updated: 2023/03/14 11:37:10 by marias-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	freed(char **p, char **q)
{
	if (*p)
		free(*p);
	*p = 0;
	if (q)
	{
		if (*q)
			free(*q);
		*q = 0;
	}
	return (0);
}

int	ft_strchr_pos(char *str, int c, int force_exit)
{
	char	chr;
	int		pos;

	if (!str)
		return (-1);
	chr = (char)c;
	pos = 0;
	while (str[pos])
	{
		if (str[pos] == chr)
			return (pos);
		pos++;
	}
	if (chr == '\0' || force_exit)
		return (pos - 1);
	return (-1);
}

size_t	ft_strlen_prot(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr_gnl(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	n;

	n = 0;
	if (!s)
		return (ft_strdup_ovs(0, 1));
	if ((size_t)start >= ft_strlen_prot(s))
		return (ft_strdup_ovs(0, 1));
	if ((unsigned int)len > ft_strlen_prot(s) - start)
		str = malloc(sizeof(char) * (ft_strlen_prot(s) - (size_t)start + 1));
	else
		str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	n = 0;
	while (n < len && s[start])
	{
		str[n] = s[start];
		start++;
		n++;
	}
	str[n] = 0;
	return (str);
}

char	*ft_strdup_ovs(char *s1, size_t extra_size)
{
	int		i;
	size_t	j;
	char	*ptr;

	ptr = malloc((ft_strlen_prot(s1) + extra_size + 1) * sizeof(char));
	if (!ptr)
		return (0);
	i = 0;
	while (s1 && s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < extra_size)
		ptr[i + j++] = 0;
	ptr[i + j] = '\0';
	return (ptr);
}
