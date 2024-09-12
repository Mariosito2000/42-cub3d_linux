/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_background.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marias-e <marias-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 15:21:56 by davgonza          #+#    #+#             */
/*   Updated: 2023/05/31 10:36:39 by marias-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../david.h"

void	ft_render_background(t_game *game)
{
	size_t	w;
	size_t	h;
	int		color;

	h = 0;
	while (h < WIN_HEIGHT)
	{
		if (h <= WIN_HEIGHT / 2)
			color = game->visual.ceiling_color;
		else
			color = game->visual.floor_color;
		w = 0;
		while (w < WIN_WIDTH)
			ft_img_pixel_put(&game->mlx.img, w++, h, color);
		h++;
	}	
}
