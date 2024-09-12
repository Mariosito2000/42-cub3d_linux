/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_door_tracker_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgonza <davgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 12:28:34 by marias-e          #+#    #+#             */
/*   Updated: 2023/06/21 12:23:33 by davgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mario_bonus.h"

static void	ft_check_ray_dist(t_ray *ray, int side)
{
	if (ray->side_dist[side] > 0)
		ray->map[side] -= ray->step[side];
}

static void	ft_render_door(t_ray ray, t_game *game, double wall_dist)
{
	double	dist;

	dist = ray.side_dist[ray.side] - ray.delta[ray.side] / 2.0f;
	if (wall_dist > dist && dist > 0)
	{
		if ((ray.side == X && ray.step[X] < 0)
			|| (ray.side == Y && ray.step[Y] < 0))
			render_column(game, ray, dist, game->visual.door_sprites[0][\
ft_get_door_frame(game, ray.map[X], ray.map[Y])]);
		else
			render_column(game, ray, dist, game->visual.door_sprites[1][\
ft_get_door_frame(game, ray.map[X], ray.map[Y])]);
	}
}

void	ft_track_door(t_ray	*ray, t_game *game)
{
	double	wall_dist;

	wall_dist = ray->side_dist[ray->side] - ray->delta[ray->side];
	while (ray->side_dist[X] >= -1.5f && ray->side_dist[Y] >= -1.5f)
	{
		if ((ray->side_dist[X] - ray->delta[X])
			>= (ray->side_dist[Y] - ray->delta[Y]))
		{
			ray->side = E_W;
			if (game->map.chart[(int)ray->map[Y]][(int)ray->map[X]] == 'D' && \
			ft_get_door_facing(game, (int)ray->map[Y], (int)ray->map[X]) == E_W)
				ft_render_door(*ray, game, wall_dist);
			ray->side_dist[X] -= ray->delta[X];
			ft_check_ray_dist(ray, X);
		}
		else
		{
			ray->side = N_S;
			if (game->map.chart[(int)ray->map[Y]][(int)ray->map[X]] == 'D' && \
			ft_get_door_facing(game, (int)ray->map[Y], (int)ray->map[X]) >= N_S)
				ft_render_door(*ray, game, wall_dist);
			ray->side_dist[Y] -= ray->delta[Y];
			ft_check_ray_dist(ray, Y);
		}
	}
}
