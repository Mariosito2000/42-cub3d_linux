/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_interact_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgonza <davgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:08:16 by davgonza          #+#    #+#             */
/*   Updated: 2023/06/21 12:23:08 by davgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../david_bonus.h"

static void	open_door(t_game *game, int x, int y)
{
	t_door	*door;

	door = game->elements.door;
	while (door)
	{
		if (door->x == x && door->y == y)
		{
			door->status = !door->status;
			if (door->status)
				game->map.mod[y][x] = 'd';
			else
				game->map.mod[y][x] = 'D';
		}
		door = door->next;
	}
}

static void	open_doors(t_game *game, int x, int y)
{
	t_terminal	*temp;
	t_door		*door;

	temp = game->elements.terminal;
	while (temp && (temp->x != x || temp->y != y))
		temp = temp->next;
	if (temp)
	{
		door = temp->door;
		while (door)
		{
			open_door(game, door->x, door->y);
			door = door->next;
		}
	}
}

void	ft_interact(t_game *game)
{
	if (game->player.facing_terminal)
		open_doors(game, \
		game->player.terminal_pos[X], game->player.terminal_pos[Y]);
}
