/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_terms_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgonza <davgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:22:17 by marias-e          #+#    #+#             */
/*   Updated: 2023/06/21 12:23:33 by davgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mario_bonus.h"

static int	is_next_2_heat(char **heat_map, int j, int i)
{
	if (heat_map[j + 1][i] == '+')
		return (1);
	if (heat_map[j - 1][i] == '+')
		return (1);
	if (heat_map[j][i + 1] == '+')
		return (1);
	if (heat_map[j][i - 1] == '+')
		return (1);
	return (0);
}

static void	ft_recursive_path(int j, int i, char **map)
{
	if (!ft_strchr("1T+", map[j - 1][i]))
	{
		map[j - 1][i] = '+';
		ft_recursive_path(j - 1, i, map);
	}
	if (!ft_strchr("1T+", map[j + 1][i]))
	{
		map[j + 1][i] = '+';
		ft_recursive_path(j + 1, i, map);
	}
	if (!ft_strchr("1T+", map[j][i - 1]))
	{
		map[j][i - 1] = '+';
		ft_recursive_path(j, i - 1, map);
	}
	if (!ft_strchr("1T+", map[j][i + 1]))
	{
		map[j][i + 1] = '+';
		ft_recursive_path(j, i + 1, map);
	}
}

static void	ft_create_heat_map(t_game *game, char ***heat_map)
{
	int	i;

	i = 0;
	*heat_map = (char **)ft_malloc(sizeof(char *) * (game->map.height + 1));
	while (i < game->map.height)
	{
		(*heat_map)[i] = ft_strdup(game->map.chart[i]);
		i++;
	}
	(*heat_map)[i] = 0;
	ft_recursive_path(game->player.pos_y, game->player.pos_x, *heat_map);
}

static void	ft_create_terms(t_game *game, char **heat_map)
{
	int	i;
	int	j;

	j = 0;
	while (j < game->map.height)
	{
		i = 0;
		while (i < game->map.width)
		{
			if (game->map.chart[j][i] == 'T' && is_next_2_heat(heat_map, j, i))
				ft_set_term(game, heat_map, j, i);
			i++;
		}
		j++;
	}
}

void	ft_check_terms(t_game *game)
{
	t_door	*iter;
	char	**heat_map;

	heat_map = 0;
	if (!game->elements.door)
		return ;
	ft_create_heat_map(game, &heat_map);
	iter = game->elements.door;
	while (iter->next)
	{
		if (heat_map[iter->y][iter->x] == '+')
			ft_term_tracker(iter, game);
		iter = iter->next;
	}
	if (heat_map[iter->y][iter->x] == '+')
		ft_term_tracker(iter, game);
	ft_create_terms(game, heat_map);
	ft_free_split(&heat_map);
}
