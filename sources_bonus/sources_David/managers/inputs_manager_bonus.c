/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs_manager_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgonza <davgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 17:30:50 by davgonza          #+#    #+#             */
/*   Updated: 2023/06/21 12:23:08 by davgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../david_bonus.h"

void	inputs_manager(int keycode, int pressed, t_game *game)
{
	if (keycode == K_W)
		game->inputs.w = pressed;
	if (keycode == K_A)
		game->inputs.a = pressed;
	if (keycode == K_S)
		game->inputs.s = pressed;
	if (keycode == K_D)
		game->inputs.d = pressed;
	if (keycode == K_LEFT)
		game->inputs.left = pressed;
	if (keycode == K_RIGHT)
		game->inputs.right = pressed;
}
