/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgonza <davgonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 10:26:57 by davgonza          #+#    #+#             */
/*   Updated: 2022/10/11 10:46:30 by davgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count(int n)
{
	int	count;

	count = 1;
	if (n < 0)
		count++;
	while (n / 10 != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

int	ft_putnbr(int nb)
{
	int	count;

	count = ft_count(nb);
	if (nb == -2147483648)
	{
		write(1, "-2", 2);
		nb = 147483648;
	}
	else if (nb < 0)
	{
		nb *= -1;
		write(1, "-", 1);
	}
	if (nb / 10 > 0)
		ft_putnbr(nb / 10);
	ft_printnbr(nb % 10);
	return (count);
}
