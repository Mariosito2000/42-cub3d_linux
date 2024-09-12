/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_manager_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgonza <davgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:55:25 by davgonza          #+#    #+#             */
/*   Updated: 2023/06/21 12:23:08 by davgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../david_bonus.h"

int	quit(void)
{
	ft_printf("Program closed\n");
	exit (0);
}

static void	input_reader(int keycode, int pressed, t_game *game)
{
	if (keycode == K_ESC)
		quit();
	inputs_manager(keycode, pressed, game);
}

int	keys_manager_press(int keycode, t_game *game)
{
	input_reader(keycode, 1, game);
	if (keycode == K_1)
		game->post.ctr_enabled = !game->post.ctr_enabled;
	if (keycode == K_2)
		game->post.vignette_enabled = !game->post.vignette_enabled;
	if (keycode == K_3)
		game->post.lines_enabled = !game->post.lines_enabled;
	if (keycode == K_4)
		game->post.flick_enabled = !game->post.flick_enabled;
	return (0);
}

int	keys_manager_release(int keycode, t_game *game)
{
	if (keycode == K_SPACE)
		ft_interact(game);
	else
		input_reader(keycode, 0, game);
	return (0);
}
