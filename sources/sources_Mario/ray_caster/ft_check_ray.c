/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_ray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marias-e <marias-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:20:25 by marias-e          #+#    #+#             */
/*   Updated: 2023/06/13 12:14:54 by marias-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mario.h"

void	ft_check_hit(t_game *game, t_ray *ray)
{
	if (ray->side_dist[ray->side] - ray->delta[ray->side] > RENDER_DIST)
	{
		ray->hit = true;
		return ;
	}
	if (ray->map[X] <= 0 || ray->map[Y] <= 0 || ray->map[X] >= game->map.width
		|| ray->map[Y] >= game->map.height)
		return ;
	if (game->map.chart[(int)ray->map[Y]][(int)ray->map[X]] == '1')
	{
		ray->hit = true;
		ft_render_wall(game, *ray);
	}
}
