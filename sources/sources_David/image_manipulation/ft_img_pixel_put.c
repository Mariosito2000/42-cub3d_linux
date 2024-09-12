/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img_pixel_put.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgonza <davgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:28:16 by davgonza          #+#    #+#             */
/*   Updated: 2023/05/31 13:25:07 by davgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../david.h"

void	ft_img_pixel_put(t_sprite *spr, size_t x, size_t y, int color)
{
	if (spr->endian == 1)
	{
		spr->buffer[y * spr->line_bytes + x * 4 + 0] = (color >> 24);
		spr->buffer[y * spr->line_bytes + x * 4 + 1] = (color >> 16) & 0xFF;
		spr->buffer[y * spr->line_bytes + x * 4 + 2] = (color >> 8) & 0xFF;
		spr->buffer[y * spr->line_bytes + x * 4 + 3] = (color) & 0xFF;
	}
	else if (spr->endian == 0)
	{
		spr->buffer[y * spr->line_bytes + x * 4 + 0] = (color) & 0xFF;
		spr->buffer[y * spr->line_bytes + x * 4 + 1] = (color >> 8) & 0xFF;
		spr->buffer[y * spr->line_bytes + x * 4 + 2] = (color >> 16) & 0xFF;
		spr->buffer[y * spr->line_bytes + x * 4 + 3] = (color >> 24);
	}
}
