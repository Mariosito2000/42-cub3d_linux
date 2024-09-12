/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_closed_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgonza <davgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 15:57:35 by davgonza          #+#    #+#             */
/*   Updated: 2023/06/21 12:23:08 by davgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../david_bonus.h"

static void	check_adjacent(char **map, size_t i, size_t j)
{
	if (map[i + 1][j] == ' ')
		ft_error_exit("Map is not closed", 1);
	if (map[i][j + 1] == ' ')
		ft_error_exit("Map is not closed", 1);
	if (map[i - 1][j] == ' ')
		ft_error_exit("Map is not closed", 1);
	if (map[i][j - 1] == ' ')
		ft_error_exit("Map is not closed", 1);
}

void	ft_check_closed(char **map, t_game *game)
{
	size_t	i;
	size_t	j;

	i = 1;
	while (map[i])
	{
		j = 1;
		while (map[i][j])
		{
			if (ft_strchr("0NESWD", map[i][j]))
				check_adjacent(map, i, j);
			if (ft_strchr("D", map[i][j]))
				ft_check_door((int)i, (int)j, game);
			j++;
		}
		i++;
	}
}
