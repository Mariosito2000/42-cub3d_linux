/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgonza <davgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:28:36 by marias-e          #+#    #+#             */
/*   Updated: 2023/06/21 12:23:33 by davgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mario_bonus.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		ft_error_exit("Wrong number of arguments\n\
Params: ./cub3d <[map_name].cub>", 1);
	game.mlx.ptr = mlx_init();
	game.elements.door = 0;
	game.elements.terminal = 0;
	ft_get_map(argv[1], &game);
	ft_get_sprites(&game);
	play(&game);
	exit(0);
}
