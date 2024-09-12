/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_doors_sprites_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgonza <davgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:33:29 by davgonza          #+#    #+#             */
/*   Updated: 2023/06/21 12:23:08 by davgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../david_bonus.h"

static void	create_red_door_front_images(t_game *game)
{
	ft_create_image("Sprites/Doors/Red/Red_Door0.xpm", \
	&game->visual.door_sprites[0][0], game);
	ft_create_image("Sprites/Doors/Red/Red_Door1.xpm", \
	&game->visual.door_sprites[0][1], game);
	ft_create_image("Sprites/Doors/Red/Red_Door2.xpm", \
	&game->visual.door_sprites[0][2], game);
	ft_create_image("Sprites/Doors/Red/Red_Door3.xpm", \
	&game->visual.door_sprites[0][3], game);
	ft_create_image("Sprites/Doors/Red/Red_Door4.xpm", \
	&game->visual.door_sprites[0][4], game);
	ft_create_image("Sprites/Doors/Red/Red_Door5.xpm", \
	&game->visual.door_sprites[0][5], game);
	ft_create_image("Sprites/Doors/Red/Red_Door6.xpm", \
	&game->visual.door_sprites[0][6], game);
	ft_create_image("Sprites/Doors/Red/Red_Door7.xpm", \
	&game->visual.door_sprites[0][7], game);
	ft_create_image("Sprites/Doors/Red/Red_Door8.xpm", \
	&game->visual.door_sprites[0][8], game);
}

static void	create_red_door_back_images(t_game *game)
{
	ft_create_image("Sprites/Doors/Red/Red_Door_Back0.xpm", \
	&game->visual.door_sprites[1][0], game);
	ft_create_image("Sprites/Doors/Red/Red_Door_Back1.xpm", \
	&game->visual.door_sprites[1][1], game);
	ft_create_image("Sprites/Doors/Red/Red_Door_Back2.xpm", \
	&game->visual.door_sprites[1][2], game);
	ft_create_image("Sprites/Doors/Red/Red_Door_Back3.xpm", \
	&game->visual.door_sprites[1][3], game);
	ft_create_image("Sprites/Doors/Red/Red_Door_Back4.xpm", \
	&game->visual.door_sprites[1][4], game);
	ft_create_image("Sprites/Doors/Red/Red_Door_Back5.xpm", \
	&game->visual.door_sprites[1][5], game);
	ft_create_image("Sprites/Doors/Red/Red_Door_Back6.xpm", \
	&game->visual.door_sprites[1][6], game);
	ft_create_image("Sprites/Doors/Red/Red_Door_Back7.xpm", \
	&game->visual.door_sprites[1][7], game);
	ft_create_image("Sprites/Doors/Red/Red_Door_Back8.xpm", \
	&game->visual.door_sprites[1][8], game);
}

void	ft_get_doors_sprites(t_game *game)
{
	create_red_door_front_images(game);
	create_red_door_back_images(game);
}
