/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marias-e <marias-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:24:47 by davgonza          #+#    #+#             */
/*   Updated: 2023/06/02 11:46:18 by marias-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../david.h"

void	ft_initialize_inputs(t_game *game)
{
	game->inputs.w = false;
	game->inputs.a = false;
	game->inputs.s = false;
	game->inputs.d = false;
	game->inputs.left = false;
	game->inputs.right = false;
}

static void	move_in_angle(t_game *game, float angle, t_bool backwards)
{
	float	x_mov;
	float	y_mov;
	int		sign;

	x_mov = SPEED * cos(angle * M_PI / 180);
	y_mov = SPEED * sin(angle * M_PI / 180);
	sign = 1;
	if (backwards)
		sign = -1;
	game->player.pos_x += x_mov * sign;
	game->player.pos_y += y_mov * sign;
}

void	player_manager(t_game *game)
{
	if (game->inputs.left)
		game->player.angle -= ANGULAR_SPEED;
	else if (game->inputs.right)
		game->player.angle += ANGULAR_SPEED;
	if (game->player.angle < 0)
		game->player.angle += 360;
	else if (game->player.angle > 360)
		game->player.angle -= 360;
	if (game->inputs.w)
		move_in_angle(game, game->player.angle, false);
	if (game->inputs.s)
		move_in_angle(game, game->player.angle, true);
	if (game->inputs.d)
		move_in_angle(game, game->player.angle + 90, false);
	if (game->inputs.a)
		move_in_angle(game, game->player.angle + 90, true);
}
