/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray_caster.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marias-e <marias-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 17:24:36 by marias-e          #+#    #+#             */
/*   Updated: 2023/05/30 17:52:02 by marias-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mario.h"

static void	ft_dda(t_game *game, t_ray *ray)
{
	ray->hit = false;
	while (ray->hit == false)
	{
		if (ray->side_dist[X] < ray->side_dist[Y])
		{
			ray->side_dist[X] += ray->delta[X];
			ray->map[X] += ray->step[X];
			ray->side = E_W;
		}
		else
		{
			ray->side_dist[Y] += ray->delta[Y];
			ray->map[Y] += ray->step[Y];
			ray->side = N_S;
		}
		ft_check_hit(game, ray);
	}
}

static void	ft_set_steps(t_game *game, t_ray *ray)
{
	if (ray->ray_dir[X] < 0)
	{
		ray->step[X] = -1;
		ray->side_dist[X] = (game->player.pos_x - ray->map[X])
			* ray->delta[X];
	}
	else
	{
		ray->step[X] = 1;
		ray->side_dist[X] = (ray->map[X] + 1.0 - game->player.pos_x)
			* ray->delta[X];
	}
	if (ray->ray_dir[Y] < 0)
	{
		ray->step[Y] = -1;
		ray->side_dist[Y] = (game->player.pos_y - ray->map[Y])
			* ray->delta[Y];
	}
	else
	{
		ray->step[Y] = 1;
		ray->side_dist[Y] = (ray->map[Y] + 1 - game->player.pos_y)
			* ray->delta[Y];
	}
	ft_dda(game, ray);
}

static void	ft_calculate_delta(t_game *game, t_ray *ray)
{
	if (ray->ray_dir[X] == 0)
		ray->delta[X] = 1e30;
	else
		ray->delta[X] = fabs(1 / ray->ray_dir[X]);
	if (ray->ray_dir[Y] == 0)
		ray->delta[Y] = 1e30;
	else
		ray->delta[Y] = fabs(1 / ray->ray_dir[Y]);
	ray->map[X] = (int)game->player.pos_x;
	ray->map[Y] = (int)game->player.pos_y;
	ft_set_steps(game, ray);
}

static void	ft_calculate_ray(t_game *game, double *dir, double *plane)
{
	t_ray	ray;

	ray.win_x = 0;
	while (ray.win_x < WIN_WIDTH)
	{
		ray.camera_x = 2 * (double)ray.win_x / (double)WIN_WIDTH - 1;
		ray.ray_dir[X] = dir[X] + plane[X] * ray.camera_x;
		ray.ray_dir[Y] = dir[Y] + plane[Y] * ray.camera_x;
		ft_calculate_delta(game, &ray);
		ray.win_x++;
	}
}

void	ft_ray_cast(t_game *game)
{
	double	dir[2];
	double	plane[2];

	dir[X] = cos((game->player.angle) * DEG_2_RAD);
	dir[Y] = sin((game->player.angle) * DEG_2_RAD);
	plane[X] = cos((game->player.angle + 90) * DEG_2_RAD)
		* (tan(FOV * DEG_2_RAD / 2));
	plane[Y] = sin((game->player.angle + 90) * DEG_2_RAD)
		* (tan(FOV * DEG_2_RAD / 2));
	ft_calculate_ray(game, dir, plane);
}
