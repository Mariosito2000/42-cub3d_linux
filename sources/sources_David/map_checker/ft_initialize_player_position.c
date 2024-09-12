/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize_player_position.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgonza <davgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 15:59:08 by davgonza          #+#    #+#             */
/*   Updated: 2023/05/22 18:00:57 by davgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../david.h"

static void	set_angle(t_player *player, char c)
{
	if (c == 'N')
		player->angle = NORTH;
	else if (c == 'S')
		player->angle = SOUTH;
	else if (c == 'E')
		player->angle = EAST;
	else if (c == 'W')
		player->angle = WEST;
}

void	ft_initialize_player_position(t_player *player, char **map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_strchr("NSEW", map[i][j]))
			{
				player->pos_x = j + 0.5f;
				player->pos_y = i + 0.5f;
				set_angle(player, map[i][j]);
				map[i][j] = '0';
				return ;
			}
			j++;
		}
		i++;
	}
}
