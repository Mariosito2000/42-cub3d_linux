/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_darken_color_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgonza <davgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:05:35 by davgonza          #+#    #+#             */
/*   Updated: 2023/06/21 12:23:08 by davgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../david_bonus.h"

int	ft_darken_color(int col, float dark_percentaje)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	r = ((col & 0xFF0000) >> 16) * (1 - dark_percentaje);
	g = ((col & 0x00FF00) >> 8) * (1 - dark_percentaje);
	b = (col & 0x0000FF) * (1 - dark_percentaje);
	col = (r << 16) + (g << 8) + b;
	return (col);
}
