/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_door_facing_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgonza <davgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:02:21 by marias-e          #+#    #+#             */
/*   Updated: 2023/06/21 12:23:33 by davgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mario_bonus.h"

int	ft_get_door_facing(t_game *game, int y, int x)
{
	t_door	*iter;

	if (!game->elements.door)
		return (-1);
	iter = game->elements.door;
	while (iter->next && (iter->x != x || iter->y != y))
		iter = iter->next;
	if (iter->x == x && iter->y == y)
		return (iter->facing);
	ft_error_exit("Coords do not belong to a door", 1);
	return (-2);
}
