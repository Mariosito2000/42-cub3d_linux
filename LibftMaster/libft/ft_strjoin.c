/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marias-e <marias-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 10:55:25 by davgonza          #+#    #+#             */
/*   Updated: 2023/03/14 11:43:17 by marias-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (0);
	str = ft_malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	i = 0;
	while (i < ft_strlen(s1))
	{
		str[i] = ((char *)s1)[i];
		i++;
	}
	j = 0;
	while ((i + j) < (ft_strlen(s1) + ft_strlen(s2)))
	{
		str[i + j] = ((char *)s2)[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}
