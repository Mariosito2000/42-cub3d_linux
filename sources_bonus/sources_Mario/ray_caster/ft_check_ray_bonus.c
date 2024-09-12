/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_ray_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgonza <davgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:20:25 by marias-e          #+#    #+#             */
/*   Updated: 2023/06/21 12:23:33 by davgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mario_bonus.h"

void	ft_check_hit(t_game *game, t_ray *ray)
{
	if (ray->side_dist[ray->side] - ray->delta[ray->side] > RENDER_DIST)
	{
		ray->hit = 1;
		return ;
	}
	if (ray->map[X] <= 0 || ray->map[Y] <= 0 || ray->map[X] >= game->map.width
		|| ray->map[Y] >= game->map.height)
		return ;
	if (ft_strchr("1T", game->map.chart[(int)ray->map[Y]][(int)ray->map[X]]))
	{
		ray->hit = game->map.chart[(int)ray->map[Y]][(int)ray->map[X]];
		ft_render_wall(game, *ray);
		ft_track_door(ray, game);
	}
}
