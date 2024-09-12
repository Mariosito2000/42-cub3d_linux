/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgonza <davgonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 17:40:06 by davgonza          #+#    #+#             */
/*   Updated: 2022/11/29 11:27:41 by davgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	str = (char *)haystack;
	if (*needle == '\0')
		return (str);
	while (len && *(str + i) && i < len)
	{
		if (*(str + i) == *needle)
		{
			j = 0;
			while (needle[j] && str[i + j] == needle[j] && (i + j < len))
			{
				if (needle[j + 1] == '\0')
					return (str + i);
				j++;
			}
		}
		i++;
	}
	return (0);
}
