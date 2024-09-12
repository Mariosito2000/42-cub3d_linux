/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_manager_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgonza <davgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:24:47 by davgonza          #+#    #+#             */
/*   Updated: 2023/06/21 12:23:08 by davgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../david_bonus.h"

void	ft_initialize_inputs(t_game *game)
{
	game->inputs.w = false;
	game->inputs.a = false;
	game->inputs.s = false;
	game->inputs.d = false;
	game->inputs.left = false;
	game->inputs.right = false;
	game->player.facing_terminal = false;
	game->player.terminal_pos[X] = 0;
	game->player.terminal_pos[Y] = 0;
}

static void	move_x(t_game *game, float x_mov, int sign)
{
	char	map_char;

	if (x_mov * sign > 0)
	{
		map_char = (game->map.chart)[(int)game->player.pos_y]
		[(int)(game->player.pos_x + x_mov * sign + 0.1f)];
		if (map_char != '1' && map_char != 'T' && !(map_char == 'D'
				&& !ft_is_door_open(game, (int)(game->player.pos_x
					+ x_mov * sign + 0.1f), (int)(game->player.pos_y))))
			game->player.pos_x += x_mov * sign;
		else
			game->player.pos_x = (int)game->player.pos_x + 0.9f;
	}
	else
	{
		map_char = (game->map.chart)[(int)game->player.pos_y]
		[(int)(game->player.pos_x + x_mov * sign - 0.1f)];
		if (map_char != '1' && map_char != 'T' && !(map_char == 'D'
				&& !ft_is_door_open(game, (int)(game->player.pos_x
					+ x_mov * sign - 0.1f), (int)(game->player.pos_y))))
			game->player.pos_x += x_mov * sign;
		else
			game->player.pos_x = (int)game->player.pos_x + 0.1f;
	}
}

static void	move_y(t_game *game, float y_mov, int sign)
{
	char	map_char;

	if (y_mov * sign > 0)
	{
		map_char = (game->map.chart)[(int)(game->player.pos_y
				+ y_mov * sign + 0.1f)][(int)(game->player.pos_x)];
		if (map_char != '1' && map_char != 'T' && !(map_char == 'D'
				&& !ft_is_door_open(game, (int)(game->player.pos_x), \
				(int)(game->player.pos_y + y_mov * sign + 0.1f))))
			game->player.pos_y += y_mov * sign;
		else
			game->player.pos_y = (int)game->player.pos_y + 0.9f;
	}
	else
	{
		map_char = (game->map.chart)[(int)(game->player.pos_y
				+ y_mov * sign - 0.1f)][(int)(game->player.pos_x)];
		if (map_char != '1' && map_char != 'T' && !(map_char == 'D'
				&& !ft_is_door_open(game, (int)(game->player.pos_x), \
				(int)(game->player.pos_y + y_mov * sign - 0.1f))))
			game->player.pos_y += y_mov * sign;
		else
			game->player.pos_y = (int)game->player.pos_y + 0.1f;
	}
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
	move_x(game, x_mov, sign);
	move_y(game, y_mov, sign);
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
