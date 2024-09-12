/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgonza <davgonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 17:25:03 by davgonza          #+#    #+#             */
/*   Updated: 2022/11/29 11:27:41 by davgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*s;
	char	chr;

	chr = (char)c;
	s = 0;
	while (*str)
	{
		if (*str == chr)
			s = (char *)str;
		str++;
	}
	if (*str == chr)
		s = (char *)str;
	return (s);
}
