/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resize_map_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgonza <davgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 15:55:16 by davgonza          #+#    #+#             */
/*   Updated: 2023/06/21 12:23:08 by davgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../david_bonus.h"

static void	copy_map(char **dest, char **src)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (src[i])
	{
		j = 0;
		while (src[i][j])
		{
			dest[i + 1][j + 1] = src[i][j];
			j++;
		}
		i++;
	}
}

/// @brief Creates a char** with the dimensions given
/// and fills it with spaces characters.
/// Null terminator is automatically asigned
/// @param height of the map
/// @param width of the map
/// @return 
static char	**create_empty_map(size_t height, size_t width)
{
	char	**empty_map;
	size_t	i;

	empty_map = ft_malloc(sizeof(char *) * (height + 1));
	empty_map[height] = 0;
	i = 0;
	while (i < height)
	{
		empty_map[i] = ft_malloc(sizeof(char) * (width + 1));
		empty_map[i][width] = 0;
		ft_memset(empty_map[i], ' ', width);
		i++;
	}
	return (empty_map);
}

void	ft_resize_map(char **raw_map, t_map *map)
{
	char	**chart;
	size_t	width;
	size_t	height;

	width = 0;
	height = 0;
	while (raw_map[height])
	{
		if (ft_strlen(raw_map[height]) > width)
			width = ft_strlen(raw_map[height]);
		height++;
	}
	chart = create_empty_map(height + 2, width + 2);
	copy_map(chart, raw_map);
	map->chart = chart;
	map->height = height + 2;
	map->width = width + 2;
}
