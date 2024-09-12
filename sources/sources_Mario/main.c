/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgonza <davgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:28:36 by marias-e          #+#    #+#             */
/*   Updated: 2023/05/31 15:18:58 by davgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mario.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		ft_error_exit("Wrong number of arguments\n\
Params: ./cub3d <[map_name].cub>", 1);
	game.mlx.ptr = mlx_init();
	ft_check_map(&game, argv[1]);
	play(&game);
	exit(0);
}
