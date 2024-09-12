/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marias-e <marias-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 10:40:18 by davgonza          #+#    #+#             */
/*   Updated: 2023/03/23 13:30:00 by marias-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	n;

	if (!s)
		return ((char *)ft_calloc(1, 1));
	if ((size_t)start >= ft_strlen(s))
		return ((char *)ft_calloc(1, 1));
	if ((unsigned int)len > ft_strlen(s) - start)
		str = ft_malloc(sizeof(char) * (ft_strlen(s) - (size_t)start + 1));
	else
		str = ft_malloc(sizeof(char) * (len + 1));
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
