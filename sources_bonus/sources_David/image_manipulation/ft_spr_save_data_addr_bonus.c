/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spr_save_data_addr_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgonza <davgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:49:59 by davgonza          #+#    #+#             */
/*   Updated: 2023/06/21 12:23:08 by davgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../david_bonus.h"

void	ft_spr_save_data_addr(t_sprite *spr)
{
	spr->buffer = mlx_get_data_addr(spr->image, &spr->pixel_bits, \
	&spr->line_bytes, &spr->endian);
	if (!spr->buffer)
		ft_error_exit("Error while getting an image data address", 1);
}
