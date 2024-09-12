/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_door_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgonza <davgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 11:54:08 by marias-e          #+#    #+#             */
/*   Updated: 2023/06/21 13:02:18 by davgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mario_bonus.h"

void	ft_check_door(int y, int x, t_game *game)
{
	if (game->map.chart[y + 1][x] == '1' && game->map.chart[y - 1][x] == '1'
		&& ft_strchr("0NSEW", game->map.chart[y][x + 1])
		&& ft_strchr("0NSEW", game->map.chart[y][x - 1]))
		ft_set_door(&game->elements.door, E_W, y, x);
	else if (game->map.chart[y][x + 1] == '1'
		&& game->map.chart[y][x - 1] == '1'
		&& ft_strchr("0NSEW", game->map.chart[y + 1][x])
		&& ft_strchr("0NSEW", game->map.chart[y - 1][x]))
		ft_set_door(&game->elements.door, N_S, y, x);
	else
		ft_error_exit("A door must have 2 side walls\
 and a clear path to be created", 1);
}
