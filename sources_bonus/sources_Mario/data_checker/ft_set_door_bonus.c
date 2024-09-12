/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_door_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgonza <davgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 11:32:17 by marias-e          #+#    #+#             */
/*   Updated: 2023/06/21 12:23:33 by davgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mario_bonus.h"

void	ft_set_door(t_door **door, int facing, int y, int x)
{
	t_door	*iter;
	t_door	*new;

	new = (t_door *)ft_malloc(sizeof(t_door));
	new->x = x;
	new->y = y;
	new->status = CLOSE;
	new->facing = facing;
	new->frame = 0;
	new->next = 0;
	if (*door)
	{
		iter = *door;
		while (iter->next)
			iter = iter->next;
		iter->next = new;
	}
	else
		*door = new;
}
