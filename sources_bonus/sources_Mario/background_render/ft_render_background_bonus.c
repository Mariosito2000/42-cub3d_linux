/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_background_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgonza <davgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 12:46:16 by marias-e          #+#    #+#             */
/*   Updated: 2023/06/21 13:06:41 by davgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../mario_bonus.h"

static void	ft_draw_pixel(t_game *game, t_horizon *ray, int y, int x)
{
	int		color;
	size_t	tx;
	size_t	ty;

	tx = (int)(game->visual.floor.width * (ray->floor[X] - (int)ray->floor[X]))
		& (game->visual.floor.width - 1);
	ty = (int)(game->visual.floor.height * (ray->floor[Y] - (int)ray->floor[Y]))
		& (game->visual.floor.height - 1);
	ray->floor[X] += ray->floor_step[X];
	ray->floor[Y] += ray->floor_step[Y];
	color = ft_get_img_pixel_color(game->visual.floor, tx, ty);
	ft_img_pixel_put(&game->mlx.img, x, y, color);
	if (!(((int)ray->floor[X] % 2) && ((int)ray->floor[Y] % 2))
		|| (game->post.flick.delay < 3 && game->post.flick_enabled))
	{
		color = ft_get_img_pixel_color(game->visual.ceiling[0], tx, ty);
		ft_img_pixel_put(&game->mlx.img, x, WIN_HEIGHT - y - 1, color);
	}
	else
	{
		color = ft_get_img_pixel_color(game->visual.ceiling[1], tx, ty);
		ft_img_pixel_put(&game->mlx.img, x, WIN_HEIGHT - y - 1, color);
	}
}

static void	ft_render_bg(t_game *game, t_horizon *ray)
{
	int	y;
	int	x;

	y = WIN_HEIGHT / 2;
	while (y < WIN_HEIGHT)
	{
		ray->p = y - WIN_HEIGHT / 2;
		ray->row_dist = ray->pos_z / ray->p;
		ray->floor_step[X] = ray->row_dist
			* (ray->ray_dir1[X] - ray->ray_dir0[X]) / WIN_WIDTH;
		ray->floor_step[Y] = ray->row_dist
			* (ray->ray_dir1[Y] - ray->ray_dir0[Y]) / WIN_WIDTH;
		ray->floor[X] = game->player.pos_x + ray->row_dist * ray->ray_dir0[X];
		ray->floor[Y] = game->player.pos_y + ray->row_dist * ray->ray_dir0[Y];
		x = 0;
		while (x < WIN_WIDTH)
		{
			ft_draw_pixel(game, ray, y, x);
			x++;
		}
		y++;
	}
}

static void	ft_set_ray(t_game *game, t_horizon *ray)
{
	double	dir[2];
	double	plane[2];

	dir[X] = cos((game->player.angle) * DEG_2_RAD);
	dir[Y] = sin((game->player.angle) * DEG_2_RAD);
	plane[X] = cos((game->player.angle + 90) * DEG_2_RAD)
		* (tan(FOV * DEG_2_RAD / 2));
	plane[Y] = sin((game->player.angle + 90) * DEG_2_RAD)
		* (tan(FOV * DEG_2_RAD / 2));
	ray->ray_dir0[X] = dir[X] - plane[X];
	ray->ray_dir0[Y] = dir[Y] - plane[Y];
	ray->ray_dir1[X] = dir[X] + plane[X];
	ray->ray_dir1[Y] = dir[Y] + plane[Y];
	ray->pos_z = WIN_HEIGHT / 2;
}

void	ft_render_background(t_game *game)
{
	t_horizon	ray;

	ft_set_ray(game, &ray);
	ft_render_bg(game, &ray);
}
