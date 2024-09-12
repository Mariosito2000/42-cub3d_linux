/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_term_tracker_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marias-e <marias-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 11:14:13 by marias-e          #+#    #+#             */
/*   Updated: 2023/06/22 16:33:38 by marias-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mario_bonus.h"

static void	ft_recursive_finder(char **map, int j, int i, int *found);

static void	ft_recursive_finder_aux(char **map, int j, int i, int *found)
{
	if (!ft_strchr("1D+", map[j][i - 1]))
	{
		if (map[j][i - 1] == 'T')
			*found = 1;
		else
		{
			map[j][i - 1] = '+';
			ft_recursive_finder(map, j, i - 1, found);
		}
	}
	if (!ft_strchr("1D+", map[j][i + 1]))
	{
		if (map[j][i + 1] == 'T')
			*found = 1;
		else
		{
			map[j][i + 1] = '+';
			ft_recursive_finder(map, j, i + 1, found);
		}
	}
}

static void	ft_recursive_finder(char **map, int j, int i, int *found)
{
	if (*found)
		return ;
	if (!ft_strchr("1D+", map[j - 1][i]))
	{
		if (map[j - 1][i] == 'T')
			*found = 1;
		else
		{
			map[j - 1][i] = '+';
			ft_recursive_finder(map, j - 1, i, found);
		}
	}
	if (!ft_strchr("1D+", map[j + 1][i]))
	{
		if (map[j + 1][i] == 'T')
			*found = 1;
		else
		{
			map[j + 1][i] = '+';
			ft_recursive_finder(map, j + 1, i, found);
		}
	}
	ft_recursive_finder_aux(map, j, i, found);
}

static void	ft_find_term(char **map, int y, int x)
{
	int	found;

	found = 0;
	ft_recursive_finder(map, y, x, &found);
	if (!found)
		ft_error_exit("Every room separated by a door must have at least one\
 functional terminal", 1);
}

static void	ft_term_tracker_aux(t_door *door, char ***map)
{
	if (door->facing == E_W)
	{
		ft_find_term(map[0], door->y, door->x + 1);
		ft_find_term(map[1], door->y, door->x - 1);
	}
	else
	{
		ft_find_term(map[0], door->y + 1, door->x);
		ft_find_term(map[1], door->y - 1, door->x);
	}
	ft_free_split(&(map[0]));
	ft_free_split(&(map[1]));
}

void	ft_term_tracker(t_door *door, t_game *game)
{
	int		i;
	char	**map[2];

	i = 0;
	map[0] = (char **)ft_malloc(sizeof(char *) * (game->map.height + 1));
	while (i < game->map.height)
	{
		map[0][i] = ft_strdup(game->map.chart[i]);
		i++;
	}
	map[0][i] = 0;
	i = 0;
	map[1] = (char **)ft_malloc(sizeof(char *) * (game->map.height + 1));
	while (i < game->map.height)
	{
		map[1][i] = ft_strdup(game->map.chart[i]);
		i++;
	}
	map[1][i] = 0;
	map[0][door->y][door->x] = '1';
	map[1][door->y][door->x] = '1';
	ft_term_tracker_aux(door, map);
}
