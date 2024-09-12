/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spr_save_data_addr.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marias-e <marias-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:49:59 by davgonza          #+#    #+#             */
/*   Updated: 2023/06/01 12:31:15 by marias-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../david.h"

void	ft_spr_save_data_addr(t_sprite *spr)
{
	spr->buffer = mlx_get_data_addr(spr->image, &spr->pixel_bits, \
	&spr->line_bytes, &spr->endian);
	if (!spr->buffer)
		ft_error_exit("Error while getting an image data address", 1);
}
