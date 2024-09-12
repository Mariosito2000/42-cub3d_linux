/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_wall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgonza <davgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:57:01 by davgonza          #+#    #+#             */
/*   Updated: 2023/06/22 15:41:17 by davgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../david.h"

static int	set_texture_x(t_ray ray, t_sprite spr, double wall_x)
{
	int	pos;

	pos = (int)(wall_x * spr.width);
	if (ray.side == E_W && ray.ray_dir[X] < 0)
		pos = spr.width - pos - 1;
	if (ray.side == N_S && ray.ray_dir[Y] > 0)
		pos = spr.width - pos - 1;
	return (pos);
}

static void	set_line_properties(t_column *column, \
double perp_dist, t_sprite spr)
{
	column->line_height = WIN_HEIGHT / perp_dist
		* (WIN_WIDTH / (float)WIN_HEIGHT / (16.0f / 9.0f));
	column->draw_start = -column->line_height / 2 + WIN_HEIGHT / 2;
	if (column->draw_start < 0)
		column->draw_start = 0;
	column->draw_end = column->line_height / 2 + WIN_HEIGHT / 2;
	if (column->draw_end >= WIN_HEIGHT)
		column->draw_end = WIN_HEIGHT;
	column->step = 1.0f * spr.height / (double)column->line_height;
	column->tex_pos = (column->draw_start - WIN_HEIGHT / 2
			+ column->line_height / 2) * column->step;
}

static void	render_column(t_game *game, t_ray ray, \
double perp_dist, t_sprite spr)
{
	t_column	column;
	double		wall_x;
	int			i;
	int			color;

	if (ray.side == N_S)
		wall_x = game->player.pos_x + perp_dist * ray.ray_dir[X];
	else
		wall_x = game->player.pos_y + perp_dist * ray.ray_dir[Y];
	wall_x -= floor(wall_x);
	column.texture[X] = set_texture_x(ray, spr, wall_x);
	set_line_properties(&column, perp_dist, spr);
	i = 0;
	while (i + column.draw_start < column.draw_end)
	{
		column.texture[Y] = (int)column.tex_pos & (spr.height - 1);
		column.tex_pos += column.step;
		color = ft_get_img_pixel_color(spr, column.texture[X], \
		column.texture[Y]);
		ft_img_pixel_put(&game->mlx.img, ray.win_x, \
		column.draw_start + i, color);
		i++;
	}
}

void	ft_render_wall(t_game *game, t_ray ray)
{
	double	dist;

	dist = ray.side_dist[ray.side] - ray.delta[ray.side];
	if (ray.side == X && ray.step[X] > 0)
		render_column(game, ray, dist, game->visual.west);
	if (ray.side == X && ray.step[X] < 0)
		render_column(game, ray, dist, game->visual.east);
	if (ray.side == Y && ray.step[Y] > 0)
		render_column(game, ray, dist, game->visual.north);
	if (ray.side == Y && ray.step[Y] < 0)
		render_column(game, ray, dist, game->visual.south);
}
