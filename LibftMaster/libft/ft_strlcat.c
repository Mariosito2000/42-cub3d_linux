/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgonza <davgonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:57:13 by davgonza          #+#    #+#             */
/*   Updated: 2022/11/29 11:27:41 by davgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	ldst;
	size_t	lsrc;

	ldst = 0;
	while (dst && dst[ldst] != '\0')
		ldst++;
	lsrc = 0;
	while (src[lsrc] != '\0')
		lsrc++;
	if (dstsize == 0)
		return (lsrc);
	i = 0;
	if (dstsize <= ldst)
		return (lsrc + dstsize);
	while (src[i] != '\0' && ((ldst + i) < (dstsize - 1)))
	{
		dst[ldst + i] = ((char *)src)[i];
		i++;
	}
	dst[ldst + i] = '\0';
	return (ldst + lsrc);
}
