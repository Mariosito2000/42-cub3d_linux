/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgonza <davgonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 10:34:10 by davgonza          #+#    #+#             */
/*   Updated: 2022/10/26 11:35:11 by davgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_strlen(char *c)
{
	int	n;

	n = 0;
	while (c[n])
		n++;
	return (n);
}

static int	ft_printnbr_base(unsigned int nbr, char *base, int base_length)
{
	int	n;

	n = 1;
	if (nbr / base_length > 0)
		n += ft_printnbr_base(nbr / base_length, base, base_length);
	ft_putchar(base[nbr % base_length]);
	return (n);
}

int	ft_putnbr_base(int nbr, char *base)
{
	int	n;

	n = ft_printnbr_base((unsigned int)nbr, base, ft_strlen(base));
	return (n);
}
