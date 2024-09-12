/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marias-e <marias-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:22:12 by marias-e          #+#    #+#             */
/*   Updated: 2023/05/22 16:49:09 by marias-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mario.h"

void	ft_check_map(t_game *game, char *file)
{
	int		fd;
	int		check;
	char	*line;

	fd = ft_check_file(file);
	ft_initialize_data(game);
	line = get_next_line(fd);
	check = 1;
	while (line && check)
	{
		ft_manage_line(line, game);
		check = ft_check_data(game);
		ft_free((void **)&line);
		line = get_next_line(fd);
	}
	if (!check)
		ft_get_map(fd, game, line);
	else
		ft_data_lack(check);
	ft_free((void **)&line);
}
