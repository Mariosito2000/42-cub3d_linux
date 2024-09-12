/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_randomize_walls_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgonza <davgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 11:51:33 by marias-e          #+#    #+#             */
/*   Updated: 2023/06/21 12:23:33 by davgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mario_bonus.h"

static int	ft_doorframe(int y, int x, t_game *game)
{
	t_door	*iter;

	if (!game->elements.door)
		return (0);
	iter = game->elements.door;
	while (iter->next)
	{
		if ((x == iter->x - 1 && y == iter->y)
			|| (x == iter->x + 1 && y == iter->y)
			|| (x == iter->x && y == iter->y + 1)
			|| (x == iter->x && y == iter->y - 1))
			return (1);
		iter = iter->next;
	}
	if ((x == iter->x - 1 && y == iter->y)
		|| (x == iter->x + 1 && y == iter->y)
		|| (x == iter->x && y == iter->y + 1)
		|| (x == iter->x && y == iter->y - 1))
		return (1);
	return (0);
}

void	ft_randomize_walls(t_game *game)
{
	int	i;
	int	j;

	game->map.mod = (char **)ft_malloc(sizeof(char *) * (game->map.height + 1));
	j = 0;
	while (j < game->map.height)
	{
		i = 0;
		game->map.mod[j] = \
			(char *)ft_malloc(sizeof(char) * (game->map.width + 1));
		while (i < game->map.width + 1)
		{
			if (game->map.chart[j][i] == '1' && !ft_doorframe(j, i, game))
				game->map.mod[j][i] = ((arc4random() % 9) + 1) + '0';
			else
				game->map.mod[j][i] = game->map.chart[j][i];
			i++;
		}
		j++;
	}
	game->map.mod[j] = 0;
}
