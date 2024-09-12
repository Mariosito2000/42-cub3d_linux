/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgonza <davgonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:24:25 by davgonza          #+#    #+#             */
/*   Updated: 2022/10/10 18:18:33 by davgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printptr(unsigned long long int ptr, char *base)
{
	int	n;

	n = 0;
	if (ptr < 16)
		n += ft_putchar(base[ptr % 16]);
	else
	{
		n = ft_printptr(ptr / 16, base);
		n += ft_putchar(base[ptr % 16]);
	}
	return (n);
}

int	ft_putptr(void *ptr)
{
	int	n;

	n = ft_putstr("0x");
	n += ft_printptr((unsigned long long int)ptr, "0123456789abcdef");
	return (n);
}
