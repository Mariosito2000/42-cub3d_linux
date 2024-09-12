/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgonza <davgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:20:13 by davgonza          #+#    #+#             */
/*   Updated: 2023/05/22 15:53:55 by davgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../david.h"

static int	skip_empty(int fd, char **line_map)
{
	char	*line;

	line = *line_map;
	while (line && line[0] == '\n')
	{
		ft_free((void **)&line);
		line = get_next_line(fd);
	}
	if (line)
	{
		*line_map = line;
		return (0);
	}
	return (1);
}

static void	copy_lines(int fd, char **line_map)
{
	char	*line;
	char	*new_map;

	line = get_next_line(fd);
	if (line && line[0] == '\n')
		ft_error_exit("Empty line in map", 1);
	while (line)
	{
		new_map = ft_strjoin(*line_map, line);
		ft_free((void **)line_map);
		ft_free((void **)&line);
		*line_map = new_map;
		line = get_next_line(fd);
		if (line && line[0] == '\n')
			ft_error_exit("Empty line in map", 1);
	}
	if ((*line_map)[ft_strlen(*line_map) - 1] == '\n')
		ft_error_exit("Empty line after map", 1);
}

static void	check_chars(char *line_map)
{
	int		i;
	t_bool	player_flag;

	i = 0;
	player_flag = false;
	while (line_map[i])
	{
		if (!ft_strchr("01NSEW \n", line_map[i]))
			ft_error_exit("Invalid character in map", 1);
		if (ft_strchr("NSEW", line_map[i]))
		{
			if (player_flag)
				ft_error_exit("Duplicated player position", 1);
			player_flag = true;
		}
		i++;
	}
	if (!player_flag)
		ft_error_exit("Missing initial player position", 1);
}

void	ft_get_map(int fd, t_game *game, char *last_line)
{
	char	*line_map;
	char	**raw_map;

	if (!last_line || !*last_line)
		ft_error_exit("No map in file", 1);
	line_map = ft_strdup(last_line);
	if (skip_empty(fd, &line_map) == 1)
		ft_error_exit("Empty map", 1);
	copy_lines(fd, &line_map);
	check_chars(line_map);
	raw_map = ft_split(line_map, '\n');
	ft_resize_map(raw_map, &(game->map));
	ft_check_closed(game->map.chart);
	ft_initialize_player_position(&game->player, game->map.chart);
	ft_free((void **)&line_map);
	ft_free_split(&raw_map);
}
