/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_darken_win_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgonza <davgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:35:34 by davgonza          #+#    #+#             */
/*   Updated: 2023/06/21 12:23:08 by davgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../david_bonus.h"

void	ft_darken_win(t_game *game, float dark_percentaje)
{
	int	i;
	int	j;
	int	col;

	i = 0;
	while (i < game->mlx.img.height)
	{
		j = 0;
		while (j < game->mlx.img.width)
		{
			col = ft_get_img_pixel_color(game->mlx.img, j, i);
			col = ft_darken_color(col, dark_percentaje);
			ft_img_pixel_put(&game->mlx.img_post, j, i, col);
			j++;
		}
		i++;
	}
	ft_swap_imgs(game);
}
