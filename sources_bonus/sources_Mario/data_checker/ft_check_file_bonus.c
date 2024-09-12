/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgonza <davgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:27:37 by marias-e          #+#    #+#             */
/*   Updated: 2023/06/21 12:23:33 by davgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mario_bonus.h"

int	ft_check_file(char *file)
{
	int	fd;

	if (ft_strlen(file) < 4 || ft_strncmp(file + (ft_strlen(file) - 4),
			".cub", 5))
		ft_error_exit("File extension is not .cub", 22);
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror(file);
		exit(13);
	}
	return (fd);
}
