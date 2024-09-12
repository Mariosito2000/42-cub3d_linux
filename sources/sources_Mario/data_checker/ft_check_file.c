/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marias-e <marias-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:27:37 by marias-e          #+#    #+#             */
/*   Updated: 2023/05/22 16:49:06 by marias-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mario.h"

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
