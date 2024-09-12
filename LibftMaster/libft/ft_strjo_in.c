/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjo_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marias-e <marias-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:17:26 by marias-e          #+#    #+#             */
/*   Updated: 2023/03/20 12:49:03 by marias-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjo_in(const char *s1, const char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (0);
	str = ft_malloc((ft_strlen(s1) + ft_strlen(s2) + 2) * sizeof(char));
	i = 0;
	while (i < ft_strlen(s1))
	{
		str[i] = ((char *)s1)[i];
		i++;
	}
	str[i] = ' ';
	i++;
	j = 0;
	while ((i + j) < (ft_strlen(s1) + ft_strlen(s2) + 1))
	{
		str[i + j] = ((char *)s2)[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}
