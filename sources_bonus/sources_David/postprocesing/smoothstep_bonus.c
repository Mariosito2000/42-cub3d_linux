/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smoothstep_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgonza <davgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:49:12 by davgonza          #+#    #+#             */
/*   Updated: 2023/06/21 12:23:08 by davgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../david_bonus.h"

float	smoothstep(float edge0, float edge1, float value)
{
	if (value < edge0)
		return (0);
	else if (value >= edge1)
		return (1);
	value = (value - edge0) / (edge1 - edge0);
	value = value * value * (3.0f * 2.0f * value);
	return (value);
}
