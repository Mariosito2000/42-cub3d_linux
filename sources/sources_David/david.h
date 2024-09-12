/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   david.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgonza <davgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:43:15 by davgonza          #+#    #+#             */
/*   Updated: 2023/05/31 15:14:32 by davgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DAVID_H
# define DAVID_H

# include "../cub3d.h"
# include <unistd.h>

typedef enum boolean	t_bool;
typedef struct s_game	t_game;
typedef struct s_player	t_player;
typedef struct s_map	t_map;
typedef struct s_sprite	t_sprite;
typedef struct s_inputs	t_inputs;
typedef struct s_ray	t_ray;

void	ft_get_map(int fd, t_game *game, char *last_line);
void	ft_resize_map(char **raw_map, t_map *map);
void	ft_check_closed(char **map);
void	ft_initialize_player_position(t_player *player, char **map);

void	ft_spr_save_data_addr(t_sprite *spr);
int		ft_get_img_pixel_color(t_sprite spr, size_t x, size_t y);
void	ft_img_pixel_put(t_sprite *spr, size_t x, size_t y, int color);

int		quit(void);
void	play(t_game *game);

void	ft_initialize_inputs(t_game *game);
int		keys_manager_press(int keycode, t_game *game);
int		keys_manager_release(int keycode, t_game *game);
void	inputs_manager(int keycode, int pressed, t_game *game);
void	player_manager(t_game *game);

void	ft_render_background(t_game *game);
void	ft_render_wall(t_game *game, t_ray ray);
#endif