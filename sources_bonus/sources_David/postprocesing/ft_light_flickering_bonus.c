/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_light_flickering_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgonza <davgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:55:23 by davgonza          #+#    #+#             */
/*   Updated: 2023/06/21 12:23:08 by davgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../david_bonus.h"

void	ft_randomise_flick_params(t_game *game)
{
	game->post.flick.amount = rand() % 7 + 1;
	game->post.flick.delay = rand() % 6 + 4;
}

void	ft_light_flickering(t_game *game)
{
	if (!game->post.flick_enabled)
		return ;
	if (game->post.next_flick_frame_count > 0)
		game->post.next_flick_frame_count--;
	if (game->post.next_flick_frame_count <= 0)
	{
		if (game->post.flick.delay < 3 && game->post.flick.delay > 0)
			ft_darken_win(game, 0.4f);
		if (game->post.flick.delay > 0)
			game->post.flick.delay--;
		else
		{
			ft_darken_win(game, 0.4f);
			game->post.flick.amount--;
			if (game->post.flick.amount <= 0)
			{
				game->post.next_flick_frame_count = \
				FLICK_MIN_DELAY + rand() % FLICK_RANGE;
				ft_randomise_flick_params(game);
			}
			else
				game->post.flick.delay = rand() % 4 + 4;
		}
	}
}
