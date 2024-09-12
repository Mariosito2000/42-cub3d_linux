/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   david_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgonza <davgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:43:15 by davgonza          #+#    #+#             */
/*   Updated: 2023/06/21 12:25:43 by davgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DAVID_BONUS_H
# define DAVID_BONUS_H

# include "../cub3d_bonus.h"
# include <unistd.h>
# include <time.h>

typedef enum boolean	t_bool;
typedef struct s_game	t_game;
typedef struct s_player	t_player;
typedef struct s_map	t_map;
typedef struct s_sprite	t_sprite;
typedef struct s_inputs	t_inputs;
typedef struct s_ray	t_ray;
typedef struct s_door	t_door;

void	ft_get_map(char *filename, t_game *game);
void	ft_resize_map(char **raw_map, t_map *map);
void	ft_check_closed(char **map, t_game *game);
void	ft_initialize_player_position(t_player *player, char **map);

void	ft_spr_save_data_addr(t_sprite *spr);
int		ft_get_img_pixel_color(t_sprite spr, size_t x, size_t y);
void	ft_img_pixel_put(t_sprite *spr, size_t x, size_t y, int color);
void	ft_get_doors_sprites(t_game *game);

int		quit(void);
void	play(t_game *game);

void	ft_initialize_inputs(t_game *game);
int		keys_manager_press(int keycode, t_game *game);
int		keys_manager_release(int keycode, t_game *game);
void	inputs_manager(int keycode, int pressed, t_game *game);
void	player_manager(t_game *game);
void	mouse_manager(t_game *game);
void	doors_manager(t_game *game);
t_bool	ft_is_door_open(t_game *game, int x, int y);
void	ft_interact(t_game *game);

void	ft_render_wall(t_game *game, t_ray ray);
void	render_minimap(t_game *game);
int		ft_get_door_frame(t_game *game, int x, int y);

void	ft_ctr_init(t_game *game, float curvature, float vignette_width);
void	ft_swap_imgs(t_game *game);
void	ft_ctr(t_game *game);

int		ft_darken_color(int col, float dark_percentaje);
float	smoothstep(float edge0, float edge1, float value);
float	saturate(float in);

void	render_column(t_game *game, t_ray ray,
			double perp_dist, t_sprite spr);
void	ft_darken_win(t_game *game, float dark_percentaje);
void	ft_light_flickering(t_game *game);

#endif