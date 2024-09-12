/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgonza <davgonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 11:42:14 by davgonza          #+#    #+#             */
/*   Updated: 2022/10/26 11:33:52 by davgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_translate(char c, va_list ptr)
{
	if (c == 'c')
		return (ft_putchar(va_arg(ptr, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(ptr, char *)));
	else if (c == 'p')
		return (ft_putptr(va_arg(ptr, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(ptr, int)));
	else if (c == 'u')
		return (ft_putunnbr(va_arg(ptr, unsigned int)));
	else if (c == 'x')
		return (ft_putnbr_base(va_arg(ptr, int), "0123456789abcdef"));
	else if (c == 'X')
		return (ft_putnbr_base(va_arg(ptr, int), "0123456789ABCDEF"));
	else if (c == '%')
		return (ft_putchar('%'));
	else
		return (0);
}

int	ft_printf(char const *format, ...)
{
	va_list	ptr;
	int		count;

	count = 0;
	va_start(ptr, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += ft_translate(*format, ptr);
		}
		else
			count += ft_putchar(*format);
		format++;
	}
	va_end(ptr);
	return (count);
}
