/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marias-e <marias-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 12:12:37 by marias-e          #+#    #+#             */
/*   Updated: 2023/05/22 16:49:11 by marias-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mario.h"

void	ft_data_lack(int code)
{
	if (code == NORTH_SPRITE)
		ft_error_exit("Missing NORTH_SPRITE", 1);
	if (code == SOUTH_SPRITE)
		ft_error_exit("Missing SOUTH_SPRITE", 1);
	if (code == EAST_SPRITE)
		ft_error_exit("Missing EAST_SPRITE", 1);
	if (code == WEST_SPRITE)
		ft_error_exit("Missing WEST_SPRITE", 1);
	if (code == FLOOR_COLOR)
		ft_error_exit("Missing FLOOR_COLOR", 1);
	if (code == CEILING_COLOR)
		ft_error_exit("Missing CEILING_COLOR", 1);
}

void	ft_data_excess(int code)
{
	if (code == NORTH_SPRITE)
		ft_error_exit("Duplicated NORTH_SPRITE assignation", 1);
	if (code == SOUTH_SPRITE)
		ft_error_exit("Duplicated SOUTH_SPRITE assignation", 1);
	if (code == EAST_SPRITE)
		ft_error_exit("Duplicated EAST_SPRITE assignation", 1);
	if (code == WEST_SPRITE)
		ft_error_exit("Duplicated WEST_SPRITE assignation", 1);
	if (code == FLOOR_COLOR)
		ft_error_exit("Duplicated FLOOR_COLOR assignation", 1);
	if (code == CEILING_COLOR)
		ft_error_exit("Duplicated CEILING_COLOR assignation", 1);
}

void	ft_data_error(int code)
{
	if (code == NORTH_SPRITE)
		ft_error_exit("NORTH_SPRITE image creation failed", 1);
	if (code == SOUTH_SPRITE)
		ft_error_exit("SOUTH_SPRITE image creation failed", 1);
	if (code == EAST_SPRITE)
		ft_error_exit("EAST_SPRITE image creation failed", 1);
	if (code == WEST_SPRITE)
		ft_error_exit("WEST_SPRITE image creation failed", 1);
	if (code == FLOOR_COLOR)
		ft_error_exit("Wrong FLOOR_COLOR format ", 1);
	if (code == CEILING_COLOR)
		ft_error_exit("Wrong CEILING_COLOR format", 1);
}
