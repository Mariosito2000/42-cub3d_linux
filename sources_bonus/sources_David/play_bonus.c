/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marias-e <marias-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:48:17 by davgonza          #+#    #+#             */
/*   Updated: 2023/06/21 13:09:02 by marias-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "david_bonus.h"

int	render_manager(t_game *game)
{
	player_manager(game);
	mouse_manager(game);
	ft_render_background(game);
	doors_manager(game);
	game->visual.term_frame = (game->visual.term_frame + 1) % (11 * 16);
	ft_ray_cast(game);
	ft_light_flickering(game);
	render_minimap(game);
	ft_ctr(game);
	mlx_put_image_to_window(game->mlx.ptr, game->mlx.win,
		game->mlx.img.image, 0, 0);
	return (0);
}

static void	set_post(t_game *game)
{
	game->post.ctr_enabled = false;
	game->post.vignette_enabled = true;
	game->post.lines_enabled = true;
	game->post.flick_enabled = false;
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
	set_post(game);
	game->post.next_flick_frame_count = FLICK_MIN_DELAY + rand() % FLICK_RANGE;
	game->post.flick.delay = rand() % 6 + 4;
	game->visual.term_frame = 0;
	srand(time(NULL));
	game->mlx.win = mlx_new_window(game->mlx.ptr, WIN_WIDTH, WIN_HEIGHT,
			"Duake\"ULTRAEXTREMEBRUTALITYEDITIONPLUS\"(REMASTERED)");
	game->mlx.img.image = mlx_new_image(game->mlx.ptr, WIN_WIDTH, WIN_HEIGHT);
	ft_spr_save_data_addr(&game->mlx.img);
	game->mlx.img.width = WIN_WIDTH;
	game->mlx.img.height = WIN_HEIGHT;
	game->mlx.img_post.image = mlx_new_image(game->mlx.ptr,
			WIN_WIDTH, WIN_HEIGHT);
	ft_spr_save_data_addr(&game->mlx.img_post);
	game->mlx.img_post.width = WIN_WIDTH;
	game->mlx.img_post.height = WIN_HEIGHT;
	set_hooks(game);
	ft_ctr_init(game, 4.0f, 100.0f);
	mlx_mouse_hide(game->mlx.ptr, game->mlx.win);
	mlx_mouse_move(game->mlx.ptr, game->mlx.win, WIN_WIDTH / 2, 0);
	mlx_loop(game->mlx.ptr);
}
