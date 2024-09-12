/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_sprites_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marias-e <marias-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 12:09:06 by marias-e          #+#    #+#             */
/*   Updated: 2023/06/21 13:08:44 by marias-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mario_bonus.h"

void	ft_create_image(char *path, t_sprite *sprite, t_game *game)
{
	sprite->image = mlx_xpm_file_to_image(game->mlx.ptr, path, &sprite->width,
			&sprite->height);
	if (!sprite->image)
		ft_error_exit("An image creation failed", 1);
	ft_spr_save_data_addr(sprite);
}

static void	ft_get_sprites_2(t_game *game)
{
	ft_create_image("Sprites/LIGHTS_ORANGE.xpm",
		&game->visual.ceiling[1], game);
	ft_create_image("Sprites/CONSOLE_D.xpm",
		&game->visual.termemenal[0], game);
	ft_create_image("Sprites/CONSOLE_M.xpm",
		&game->visual.termemenal[1], game);
	ft_create_image("Sprites/CONSOLE_MONGUS.xpm",
		&game->visual.termemenal[2], game);
	ft_create_image("Sprites/CONSOLE_DOOM.xpm",
		&game->visual.termemenal[3], game);
	ft_create_image("Sprites/CONSOLE_MARIO.xpm",
		&game->visual.termemenal[4], game);
	ft_create_image("Sprites/CONSOLE_TRI.xpm",
		&game->visual.termemenal[5], game);
	ft_create_image("Sprites/CONSOLE_CREEPER.xpm",
		&game->visual.termemenal[6], game);
	ft_create_image("Sprites/CONSOLE_SANS.xpm",
		&game->visual.termemenal[7], game);
	ft_create_image("Sprites/CONSOLE_CUB3D.xpm",
		&game->visual.termemenal[8], game);
	ft_create_image("Sprites/CONSOLE_ISAAC.xpm",
		&game->visual.termemenal[9], game);
	ft_create_image("Sprites/CONSOLE_LAMBDA.xpm",
		&game->visual.termemenal[10], game);
}

void	ft_get_sprites(t_game *game)
{
	ft_create_image("Sprites/FLOOR_2A1685546504.xpm",
		&game->visual.floor, game);
	ft_create_image("Sprites/LIGHT_1A1685546509.xpm",
		&game->visual.ceiling[0], game);
	ft_create_image("Sprites/TECH_1A1685546519.xpm",
		&game->visual.wall[0], game);
	ft_create_image("Sprites/TECH_0A1685546518.xpm",
		&game->visual.wall[1], game);
	ft_create_image("Sprites/TECH_1C1685546520.xpm",
		&game->visual.wall[2], game);
	ft_create_image("Sprites/TECH_1E1685546520.xpm",
		&game->visual.wall[3], game);
	ft_create_image("Sprites/TECH_2A1685546520.xpm",
		&game->visual.wall[4], game);
	ft_create_image("Sprites/TECH_3A1685546521.xpm",
		&game->visual.wall[5], game);
	ft_create_image("Sprites/TECH_3C1685546521.xpm",
		&game->visual.wall[6], game);
	ft_create_image("Sprites/TECH_3D1685546521.xpm",
		&game->visual.wall[7], game);
	ft_create_image("Sprites/TECH_3E1685546521.xpm",
		&game->visual.wall[8], game);
	ft_get_doors_sprites(game);
	ft_get_sprites_2(game);
}
