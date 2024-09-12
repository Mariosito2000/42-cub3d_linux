/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marias-e <marias-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 16:53:18 by davgonza          #+#    #+#             */
/*   Updated: 2023/03/14 11:45:14 by marias-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_num_len(int n)
{
	int				len;
	unsigned int	num;

	len = 1;
	num = n;
	if (n < 0)
	{
		num = -n;
		len++;
	}
	while (num > 9)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int				len;
	unsigned int	num;
	char			*str;

	len = ft_num_len(n);
	num = n;
	str = (char *)ft_malloc((len + 1) * sizeof(char));
	if (n < 0)
	{
		num = -n;
		str[0] = '-';
	}
	str[len] = '\0';
	if (num == 0)
		str[len - 1] = '0';
	while (num > 0)
	{
		str[len - 1] = num % 10 + '0';
		num /= 10;
		len--;
	}
	return (str);
}
