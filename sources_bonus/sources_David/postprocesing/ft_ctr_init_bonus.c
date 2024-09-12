/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctr_init_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgonza <davgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 12:20:32 by davgonza          #+#    #+#             */
/*   Updated: 2023/06/21 12:23:08 by davgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../david_bonus.h"

static void	calculate_uv(t_sprite spr, float curvature, int *xy, float *uv)
{
	float	offset[2];

	uv[X] = ((float)xy[X] / (float)spr.width) * 2.0f - 1;
	uv[Y] = ((float)xy[Y] / (float)spr.height) * 2.0f - 1;
	offset[X] = uv[X] / curvature;
	offset[Y] = uv[Y] / curvature;
	uv[X] = (uv[X] + uv[X] * offset[Y] * offset[Y]) * 0.5f + 0.5f;
	uv[Y] = (uv[Y] + uv[Y] * offset[X] * offset[X]) * 0.5f + 0.5f;
}

static float	v_value(float vignette_width, float *uv)
{
	float			vignette[2];
	float			vignette_mult;

	uv[X] = uv[X] * 2.0f - 1.0f;
	uv[Y] = uv[Y] * 2.0f - 1.0f;
	vignette[X] = vignette_width / (float)WIN_WIDTH;
	vignette[Y] = vignette_width / (float)WIN_HEIGHT;
	vignette[X] = smoothstep(0, vignette[X], 1.0f - fabs(uv[X]));
	vignette[Y] = smoothstep(0, vignette[Y], 1.0f - fabs(uv[Y]));
	vignette[X] = saturate(vignette[X]);
	vignette[Y] = saturate(vignette[Y]);
	vignette_mult = vignette[X] * vignette[Y];
	return (vignette_mult);
}

static void	save_ctr_line(float ***ctr_lines, int *xy, float *uv)
{
	ctr_lines[xy[Y]][xy[X]] = ft_malloc(sizeof(float) * 2);
	ctr_lines[xy[Y]][xy[X]][0] = (cos(uv[Y] * WIN_HEIGHT) + 1.0f)
		* 0.135f + 1.0f;
	ctr_lines[xy[Y]][xy[X]][1] = (sin(uv[Y] * WIN_HEIGHT) + 1.0f)
		* 0.15f + 1.0f;
}

static void	save_ctr_uv(float ***ctr_uv, int *xy, float *uv)
{
	ctr_uv[xy[Y]][xy[X]] = ft_malloc(sizeof(float) * 2);
	ctr_uv[xy[Y]][xy[X]][X] = 0;
	ctr_uv[xy[Y]][xy[X]][Y] = 0;
	if (!(uv[X] < 0 || uv[X] > 1 || uv[Y] < 0
			|| uv[Y] > 1))
	{
		ctr_uv[xy[Y]][xy[X]][X] = uv[X];
		ctr_uv[xy[Y]][xy[X]][Y] = uv[Y];
	}
}

void	ft_ctr_init(t_game *game, float curvature, float vignette_width)
{
	int		xy[2];
	float	uv[2];

	game->post.ctr_uv = ft_malloc(sizeof(float **) * WIN_HEIGHT);
	game->post.ctr_vignette = ft_malloc(sizeof(float *) * WIN_HEIGHT);
	game->post.ctr_lines = ft_malloc(sizeof(float **) * WIN_HEIGHT);
	xy[Y] = 0;
	while (xy[Y] < game->mlx.img.height)
	{
		xy[X] = 0;
		game->post.ctr_uv[xy[Y]] = ft_malloc(sizeof(float *) * WIN_WIDTH);
		game->post.ctr_vignette[xy[Y]] = ft_malloc(sizeof(float) * WIN_WIDTH);
		game->post.ctr_lines[xy[Y]] = ft_malloc(sizeof(float *) * WIN_WIDTH);
		while (xy[X] < game->mlx.img.width)
		{
			calculate_uv(game->mlx.img, curvature, xy, uv);
			save_ctr_line(game->post.ctr_lines, xy, uv);
			save_ctr_uv(game->post.ctr_uv, xy, uv);
			game->post.ctr_vignette[xy[Y]][xy[X]] = v_value(vignette_width, uv);
			xy[X]++;
		}
		xy[Y]++;
	}
}
