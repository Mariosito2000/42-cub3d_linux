/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgonza <davgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:55:25 by davgonza          #+#    #+#             */
/*   Updated: 2023/05/22 17:43:30 by davgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../david.h"

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
	return (0);
}

int	keys_manager_release(int keycode, t_game *game)
{
	input_reader(keycode, 0, game);
	return (0);
}
