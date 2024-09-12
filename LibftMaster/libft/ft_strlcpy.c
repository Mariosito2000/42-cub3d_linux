/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgonza <davgonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:55:40 by davgonza          #+#    #+#             */
/*   Updated: 2022/11/29 11:27:41 by davgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while ((i + 1) < dstsize && *(src + i) != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize > 0)
		*(dst + i) = '\0';
	while (*(src + len))
		len++;
	return (len);
}
