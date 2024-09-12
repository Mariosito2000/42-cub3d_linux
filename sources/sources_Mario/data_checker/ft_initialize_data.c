/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize_data.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marias-e <marias-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:50:58 by marias-e          #+#    #+#             */
/*   Updated: 2023/05/22 16:49:33 by marias-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mario.h"

void	ft_initialize_data(t_game *game)
{
	game->visual.ceiling_color = -1;
	game->visual.floor_color = -1;
	game->visual.east.image = 0;
	game->visual.south.image = 0;
	game->visual.north.image = 0;
	game->visual.west.image = 0;
	game->player.angle = 69;
}
