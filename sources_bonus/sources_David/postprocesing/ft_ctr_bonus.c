/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctr_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgonza <davgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 12:20:32 by davgonza          #+#    #+#             */
/*   Updated: 2023/06/21 12:23:08 by davgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../david_bonus.h"

static int	old(int color, float *crt_lines, float dark, t_postpro post)
{
	float	r;
	float	g;
	float	b;

	r = ((color & 0xFF0000) >> 16);
	g = ((color & 0x00FF00) >> 8);
	b = (color & 0x0000FF);
	if (post.lines_enabled)
	{
		r *= crt_lines[0];
		if (r > 255)
			r = 255;
		g *= crt_lines[1];
		if (g > 255)
			g = 255;
		b *= crt_lines[0];
		if (b > 255)
			b = 255;
	}
	if (!post.vignette_enabled)
		dark = 1;
	color = (((int)(r * dark)) << 16) + (((int)(g * dark)) << 8)
		+ (int)(b * dark);
	return (color);
}

void	ft_ctr(t_game *game)
{
	int		xy[2];
	int		color;

	if (!game->post.ctr_enabled)
		return ;
	xy[Y] = -1;
	while (++xy[Y] < game->mlx.img.height)
	{
		xy[X] = -1;
		while (++xy[X] < game->mlx.img.width)
		{
			color = 0;
			if (game->post.ctr_uv[xy[Y]][xy[X]][X]
				&& game->post.ctr_uv[xy[Y]][xy[X]][Y])
			{
				color = ft_get_img_pixel_color(game->mlx.img, \
				game->post.ctr_uv[xy[Y]][xy[X]][X] * WIN_WIDTH, \
				game->post.ctr_uv[xy[Y]][xy[X]][Y] * WIN_HEIGHT);
				color = old(color, game->post.ctr_lines[xy[Y]][xy[X]], \
					game->post.ctr_vignette[xy[Y]][xy[X]], game->post);
			}
			ft_img_pixel_put(&game->mlx.img_post, xy[X], xy[Y], color);
		}
	}
	ft_swap_imgs(game);
}
