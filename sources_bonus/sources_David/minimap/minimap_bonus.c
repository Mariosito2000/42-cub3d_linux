/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgonza <davgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 12:50:20 by davgonza          #+#    #+#             */
/*   Updated: 2023/06/21 12:23:08 by davgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../david_bonus.h"

static int	is_visible(int color)
{
	if (color == MINIMAP_WALL || color == MINIMAP_VOID
		|| color == MINIMAP_TERMINAL || color == MINIMAP_DOOR_CLOSED)
		return (0);
	return (1);
}

static void	render_minimap_cone(t_game *game)
{
	float	angle;
	int		minimap_player_pos[2];
	int		i;

	angle = game->player.angle - FOV / 2.0f;
	minimap_player_pos[X] = MINIMAP_OFFSET_X + MINIMAP_SIZE / 2;
	minimap_player_pos[Y] = MINIMAP_OFFSET_Y + MINIMAP_SIZE / 2;
	while (angle < game->player.angle + FOV / 2.0f)
	{
		i = MINIMAP_P_SIZE / 2.0f - 1;
		while (i < MINIMAP_CONE_RANGE)
		{
			if (!is_visible(ft_get_img_pixel_color(game->mlx.img, \
			minimap_player_pos[X] + cos(angle * DEG_2_RAD) * i, \
			minimap_player_pos[Y] + sin(angle * DEG_2_RAD) * i)))
				break ;
			ft_img_pixel_put(&game->mlx.img, \
			minimap_player_pos[X] + cos(angle * DEG_2_RAD) * i, \
			minimap_player_pos[Y] + sin(angle * DEG_2_RAD) * i, \
			MINIMAP_CONE);
			i++;
		}
		angle++;
	}
}

static void	render_minimap_palyer(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < MINIMAP_P_SIZE)
	{
		j = 0;
		while (j < MINIMAP_P_SIZE)
		{
			if (pow((i - MINIMAP_P_SIZE / 2) * 2, 2) + \
			pow((j - MINIMAP_P_SIZE / 2) * 2, 2) < pow(MINIMAP_P_SIZE, 2))
				ft_img_pixel_put(&game->mlx.img, \
					j + MINIMAP_OFFSET_X + MINIMAP_SIZE / 2
					- MINIMAP_P_SIZE / 2, \
					i + MINIMAP_OFFSET_Y + MINIMAP_SIZE / 2
					- MINIMAP_P_SIZE / 2, \
					MINIMAP_PLAYER);
			j++;
		}
		i++;
	}
}

static void	render_minimap_pixel(t_game *game, int *pos, int i, int j)
{
	if (pos[Y] < 0 || pos[Y] >= game->map.height || pos[X] < 0
		|| pos[X] >= game->map.width
		|| game->map.chart[pos[Y]][pos[X]] == ' ')
		ft_img_pixel_put(&game->mlx.img, j + MINIMAP_OFFSET_X,
			i + MINIMAP_OFFSET_Y, MINIMAP_VOID);
	else if (game->map.chart[pos[Y]][pos[X]] == '1')
		ft_img_pixel_put(&game->mlx.img, j + MINIMAP_OFFSET_X,
			i + MINIMAP_OFFSET_Y, MINIMAP_WALL);
	else if (game->map.chart[pos[Y]][pos[X]] == 'T')
		ft_img_pixel_put(&game->mlx.img, j + MINIMAP_OFFSET_X,
			i + MINIMAP_OFFSET_Y, MINIMAP_TERMINAL);
	else if (game->map.chart[pos[Y]][pos[X]] == '0')
		ft_img_pixel_put(&game->mlx.img, j + MINIMAP_OFFSET_X,
			i + MINIMAP_OFFSET_Y, MINIMAP_GROUND);
	else if (game->map.mod[pos[Y]][pos[X]] == 'D')
		ft_img_pixel_put(&game->mlx.img, j + MINIMAP_OFFSET_X,
			i + MINIMAP_OFFSET_Y, MINIMAP_DOOR_CLOSED);
	else if (game->map.mod[pos[Y]][pos[X]] == 'd')
		ft_img_pixel_put(&game->mlx.img, j + MINIMAP_OFFSET_X,
			i + MINIMAP_OFFSET_Y, MINIMAP_DOOR_OPEN);
}

void	render_minimap(t_game *game)
{
	int	i;
	int	j;
	int	pos[2];

	i = 0;
	while (i < MINIMAP_SIZE && i + MINIMAP_OFFSET_Y < game->mlx.img.height)
	{
		j = 0;
		while (j < MINIMAP_SIZE && j + MINIMAP_OFFSET_X < game->mlx.img.width)
		{
			pos[X] = game->player.pos_x + (j - MINIMAP_SIZE / 2.0f)
				/ (float)MINIMAP_SIZE * 2.0f * MINIMAP_RANGE;
			pos[Y] = game->player.pos_y + (i - MINIMAP_SIZE / 2.0f)
				/ (float)MINIMAP_SIZE * 2.0f * MINIMAP_RANGE;
			render_minimap_pixel(game, pos, i, j);
			if (j <= 2 || j >= MINIMAP_SIZE - 1 - 2
				|| i <= 2 || i >= MINIMAP_SIZE - 1 - 2)
				ft_img_pixel_put(&game->mlx.img, j + MINIMAP_OFFSET_X,
					i + MINIMAP_OFFSET_Y, 0xFFFFFF);
			j++;
		}
		i++;
	}
	render_minimap_cone(game);
	render_minimap_palyer(game);
}
