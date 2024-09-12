/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marias-e <marias-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 12:41:26 by marias-e          #+#    #+#             */
/*   Updated: 2023/05/22 16:49:21 by marias-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mario.h"

void	ft_manage_line(char *line, t_game *game)
{
	if (!line || !ft_strncmp(line, "\n", 2))
		return ;
	if (!ft_strncmp(line, "NO ", 3))
		ft_get_data(1, line, game);
	else if (!ft_strncmp(line, "SO ", 3))
		ft_get_data(2, line, game);
	else if (!ft_strncmp(line, "EA ", 3))
		ft_get_data(3, line, game);
	else if (!ft_strncmp(line, "WE ", 3))
		ft_get_data(4, line, game);
	else if (!ft_strncmp(line, "F ", 2))
		ft_get_data(5, line, game);
	else if (!ft_strncmp(line, "C ", 2))
		ft_get_data(6, line, game);
	else
		ft_error_exit("Graphic data is wrong", 1);
}
