/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_door_open_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgonza <davgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 17:27:58 by davgonza          #+#    #+#             */
/*   Updated: 2023/06/21 12:23:08 by davgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../david_bonus.h"

t_bool	ft_is_door_open(t_game *game, int x, int y)
{
	t_door	*temp;

	temp = game->elements.door;
	while (temp)
	{
		if (temp->x == x && temp->y == y)
		{
			if (temp->frame > 5)
				return (true);
			return (false);
		}
		temp = temp->next;
	}
	return (false);
}
