/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgonza <davgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:48:17 by davgonza          #+#    #+#             */
/*   Updated: 2023/05/31 17:34:03 by davgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "david.h"

int	render_manager(t_game *game)
{
	ft_render_background(game);
	player_manager(game);
	ft_ray_cast(game);
	mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, game->mlx.img.image, \
	0, 0);
	return (0);
}

static void	save_walls_data(t_game *game)
{
	ft_spr_save_data_addr(&game->visual.east);
	ft_spr_save_data_addr(&game->visual.west);
	ft_spr_save_data_addr(&game->visual.north);
	ft_spr_save_data_addr(&game->visual.south);
}

static void	set_hooks(t_game *game)
{
	mlx_hook(game->mlx.win, 2, 1L << 0, keys_manager_press, game);
	mlx_hook(game->mlx.win, 3, 1L << 1, keys_manager_release, game);
	mlx_hook(game->mlx.win, 17, 1L << 17, quit, 0);
	mlx_loop_hook(game->mlx.ptr, render_manager, game);
}

void	play(t_game *game)
{
	ft_initialize_inputs(game);
	save_walls_data(game);
	game->mlx.win = mlx_new_window(game->mlx.ptr,
			WIN_WIDTH, WIN_HEIGHT, "cub3d");
	game->mlx.img.image = mlx_new_image(game->mlx.ptr, WIN_WIDTH, WIN_HEIGHT);
	ft_spr_save_data_addr(&game->mlx.img);
	set_hooks(game);
	mlx_loop(game->mlx.ptr);
}
