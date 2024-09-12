/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_term_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgonza <davgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 11:47:39 by marias-e          #+#    #+#             */
/*   Updated: 2023/06/21 12:23:33 by davgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mario_bonus.h"

static void	ft_recursive_door_set(t_game *game, char **map, int j, int i);

static void	ft_set_term_door(t_game *game, int j, int i)
{
	t_terminal	*iter;
	t_door		*door;
	t_door		*new_door;

	iter = game->elements.terminal;
	while (iter->next)
		iter = iter->next;
	door = iter->door;
	while (door && door->next)
	{
		if (door->x == i && door->y == j)
			return ;
		door = door->next;
	}
	if (door && door->x == i && door->y == j)
		return ;
	new_door = game->elements.door;
	while (new_door->x != i || new_door->y != j)
		new_door = new_door->next;
	if (!iter->door)
		ft_copy_door(&(iter->door), new_door);
	else
		ft_copy_door(&door, new_door);
}

static void	ft_recursive_door_set_2(t_game *game, char **map, int j, int i)
{
	if (!ft_strchr("1T+", map[j][i - 1]))
	{
		if (map[j][i - 1] == 'D')
			ft_set_term_door(game, j, i - 1);
		else
		{
			map[j][i - 1] = '+';
			ft_recursive_door_set(game, map, j, i - 1);
		}
	}
	if (!ft_strchr("1T+", map[j][i + 1]))
	{
		if (map[j][i + 1] == 'D')
			ft_set_term_door(game, j, i + 1);
		else
		{
			map[j][i + 1] = '+';
			ft_recursive_door_set(game, map, j, i + 1);
		}
	}
}

static void	ft_recursive_door_set(t_game *game, char **map, int j, int i)
{
	if (!ft_strchr("1T+", map[j - 1][i]))
	{
		if (map[j - 1][i] == 'D')
			ft_set_term_door(game, j - 1, i);
		else
		{
			map[j - 1][i] = '+';
			ft_recursive_door_set(game, map, j - 1, i);
		}
	}
	if (!ft_strchr("1T+", map[j + 1][i]))
	{
		if (map[j + 1][i] == 'D')
			ft_set_term_door(game, j + 1, i);
		else
		{
			map[j + 1][i] = '+';
			ft_recursive_door_set(game, map, j + 1, i);
		}
	}
	ft_recursive_door_set_2(game, map, j, i);
}

static void	ft_new_term(t_game *game, int j, int i)
{
	t_terminal	*term;
	t_terminal	*iter;

	term = (t_terminal *)ft_malloc(sizeof(t_terminal));
	term->frame = 0;
	term->x = i;
	term->y = j;
	term->next = 0;
	term->door = 0;
	if (!game->elements.terminal)
		game->elements.terminal = term;
	else
	{
		iter = game->elements.terminal;
		while (iter->next)
			iter = iter->next;
		iter->next = term;
	}
}

void	ft_set_term(t_game *game, char **heat_map, int j, int i)
{
	int			n;
	char		**map;

	n = 0;
	map = (char **)ft_malloc(sizeof(char *) * (game->map.height + 1));
	while (n < game->map.height)
	{
		map[n] = ft_strdup(game->map.chart[n]);
		n++;
	}
	map[n] = 0;
	ft_new_term(game, j, i);
	if (heat_map[j + 1][i] == '+')
		ft_recursive_door_set(game, map, j + 1, i);
	if (heat_map[j - 1][i] == '+')
		ft_recursive_door_set(game, map, j - 1, i);
	if (heat_map[j][i - 1] == '+')
		ft_recursive_door_set(game, map, j, i - 1);
	if (heat_map[j][i + 1] == '+')
		ft_recursive_door_set(game, map, j, i + 1);
	ft_free_split(&map);
}
