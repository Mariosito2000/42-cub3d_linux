/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marias-e <marias-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 11:48:57 by marias-e          #+#    #+#             */
/*   Updated: 2023/05/22 16:48:55 by marias-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mario.h"

int	ft_check_data(t_game *game)
{
	if (!game->visual.north.image)
		return (1);
	if (!game->visual.south.image)
		return (2);
	if (!game->visual.east.image)
		return (3);
	if (!game->visual.west.image)
		return (4);
	if (game->visual.floor_color == -1)
		return (5);
	if (game->visual.ceiling_color == -1)
		return (6);
	return (0);
}
