/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_door_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgonza <davgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:55:45 by marias-e          #+#    #+#             */
/*   Updated: 2023/06/21 12:23:33 by davgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mario_bonus.h"

void	ft_copy_door(t_door **door, t_door *new_door)
{
	t_door	*next;

	next = (t_door *)ft_malloc(sizeof(t_door));
	*next = *new_door;
	next->next = 0;
	if (!*door)
		*door = next;
	else
		(*door)->next = next;
}
