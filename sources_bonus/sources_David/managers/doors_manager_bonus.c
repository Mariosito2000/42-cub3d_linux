/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors_manager_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgonza <davgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:34:06 by davgonza          #+#    #+#             */
/*   Updated: 2023/06/21 12:23:08 by davgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../david_bonus.h"

void	doors_manager(t_game *game)
{
	t_door	*temp;

	temp = game->elements.door;
	while (temp)
	{
		if (temp->frame > 0 && temp->status == CLOSE)
			temp->frame--;
		else if (temp->frame < 8 && temp->status == OPEN)
			temp->frame++;
		temp = temp->next;
	}
}
