/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marias-e <marias-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:15:36 by marias-e          #+#    #+#             */
/*   Updated: 2023/05/22 16:17:49 by marias-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mario.h"

void	ft_get_data(int code, char *line, t_game *game)
{
	int		i;
	char	*info;

	i = 2;
	while (line[i] == ' ')
		i++;
	info = ft_substr(line, i, ft_strlen(line) - i);
	info[ft_strlen(info) - 1] = 0;
	if (code <= 4)
		ft_process_sprite(info, code, game);
	else
		ft_process_rgb(info, code, game);
	ft_free((void **)&info);
}
