/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_manager_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgonza <davgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 12:47:49 by davgonza          #+#    #+#             */
/*   Updated: 2023/06/21 12:23:08 by davgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../david_bonus.h"

void	mouse_manager(t_game *game)
{
	int	x;
	int	y;

	mlx_mouse_get_pos(game->mlx.ptr, game->mlx.win, &x, &y);
	game->player.angle += (x - WIN_WIDTH / 2) * 0.05f;
	mlx_mouse_move(game->mlx.ptr, game->mlx.win, WIN_WIDTH / 2, 0);
}
