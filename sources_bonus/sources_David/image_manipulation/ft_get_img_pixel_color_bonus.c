/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_img_pixel_color_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgonza <davgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:46:24 by davgonza          #+#    #+#             */
/*   Updated: 2023/06/21 12:23:08 by davgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../david_bonus.h"

int	ft_get_img_pixel_color(t_sprite spr, size_t x, size_t y)
{
	int	color;
	int	argb[4];

	argb[0] = 0;
	argb[1] = 0;
	argb[2] = 0;
	argb[3] = 0;
	if (spr.endian == 1)
	{
		argb[0] = (unsigned char)spr.buffer[y * spr.line_bytes + x * 4 + 0];
		argb[1] = (unsigned char)spr.buffer[y * spr.line_bytes + x * 4 + 1];
		argb[2] = (unsigned char)spr.buffer[y * spr.line_bytes + x * 4 + 2];
		argb[3] = (unsigned char)spr.buffer[y * spr.line_bytes + x * 4 + 3];
	}
	else if (spr.endian == 0)
	{
		argb[3] = (unsigned char)spr.buffer[y * spr.line_bytes + x * 4 + 0];
		argb[2] = (unsigned char)spr.buffer[y * spr.line_bytes + x * 4 + 1];
		argb[1] = (unsigned char)spr.buffer[y * spr.line_bytes + x * 4 + 2];
		argb[0] = (unsigned char)spr.buffer[y * spr.line_bytes + x * 4 + 3];
	}
	if (argb[0] != 0)
		return (-1);
	color = (argb[1] << 16) + (argb[2] << 8) + argb[3];
	return (color);
}
