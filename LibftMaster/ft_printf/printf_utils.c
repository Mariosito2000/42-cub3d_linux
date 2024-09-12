/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgonza <davgonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:49:52 by davgonza          #+#    #+#             */
/*   Updated: 2022/10/26 11:34:54 by davgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	n;

	n = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (*str != '\0')
	{
		write(1, &(*str), 1);
		str++;
		n++;
	}
	return (n);
}

void	ft_printnbr(char c)
{
	c += '0';
	write(1, &c, 1);
}

int	ft_putunnbr(unsigned int nbr)
{
	int	n;

	if (nbr / 10 > 0)
		ft_putunnbr(nbr / 10);
	ft_printnbr(nbr % 10);
	n = 1;
	while (nbr / 10)
	{
		nbr /= 10;
		n++;
	}
	return (n);
}
