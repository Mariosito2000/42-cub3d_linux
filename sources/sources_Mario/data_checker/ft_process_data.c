/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgonza <davgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:37:34 by marias-e          #+#    #+#             */
/*   Updated: 2023/05/26 13:31:35 by davgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mario.h"

static void	ft_set_sprite_data(int h, int w, t_sprite *spr, void *place_holder)
{
	spr->image = place_holder;
	spr->height = h;
	spr->width = w;
}

void	ft_process_sprite(char *info, int code, t_game *game)
{
	int		w;
	int		h;
	void	*place_holder;

	if ((code == NORTH_SPRITE && game->visual.north.image)
		|| (code == SOUTH_SPRITE && game->visual.south.image)
		|| (code == EAST_SPRITE && game->visual.east.image)
		|| (code == WEST_SPRITE && game->visual.west.image))
		ft_data_excess(code);
	place_holder = mlx_xpm_file_to_image(game->mlx.ptr, info, &w, &h);
	if (!place_holder)
		ft_data_error(code);
	else if (code == NORTH_SPRITE)
		ft_set_sprite_data(h, w, &game->visual.north, place_holder);
	else if (code == SOUTH_SPRITE)
		ft_set_sprite_data(h, w, &game->visual.south, place_holder);
	else if (code == EAST_SPRITE)
		ft_set_sprite_data(h, w, &game->visual.east, place_holder);
	else if (code == WEST_SPRITE)
		ft_set_sprite_data(h, w, &game->visual.west, place_holder);
}

static void	ft_rgbtoi(int *rgb, int code, t_game *game)
{
	if (rgb[0] < 0 || rgb[0] > 255 || rgb[1] < 0 || rgb[1] > 255
		|| rgb[2] < 0 || rgb[2] > 255)
		ft_data_error(code);
	if (code == FLOOR_COLOR)
		game->visual.floor_color = (rgb[0] << 16) + (rgb[1] << 8) + rgb[2];
	else if (code == CEILING_COLOR)
		game->visual.ceiling_color = (rgb[0] << 16) + (rgb[1] << 8) + rgb[2];
}

void	ft_process_rgb(char *info, int code, t_game *game)
{
	int		i;
	int		c;
	int		rgb[3];

	if ((code == CEILING_COLOR && game->visual.ceiling_color != -1)
		|| (code == FLOOR_COLOR && game->visual.floor_color != -1))
		ft_data_excess(code);
	i = 0;
	c = 0;
	if (ft_strlen(info) < 5)
		ft_data_error(code);
	while (c < 3)
	{
		rgb[c] = ft_atoi(&info[i]);
		if (!ft_isdigit(info[i]))
			ft_data_error(code);
		while (ft_isdigit(info[i]))
			i++;
		if (info[i] == ',' && c < 2)
			i++;
		else if (c < 2 || (c == 2 && info[i]))
			ft_data_error(code);
		c++;
	}
	ft_rgbtoi(rgb, code, game);
}
