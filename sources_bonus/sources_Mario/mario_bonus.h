/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mario_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgonza <davgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:39:38 by marias-e          #+#    #+#             */
/*   Updated: 2023/06/21 12:25:08 by davgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MARIO_BONUS_H
# define MARIO_BONUS_H

# include "../cub3d_bonus.h"

typedef struct s_game	t_game;
typedef struct s_ray	t_ray;
typedef struct s_door	t_door;
typedef struct s_sprite	t_sprite;

void	ft_error_exit(char *error_str, int error_code);

void	ft_create_image(char *path, t_sprite *sprite, t_game *game);
void	ft_get_sprites(t_game *game);

int		ft_check_file(char *file);

void	ft_check_door(int y, int x, t_game *game);
void	ft_set_door(t_door **door, int facing, int y, int x);
void	ft_check_terms(t_game *game);
void	ft_term_tracker(t_door *door, t_game *game);
void	ft_set_term(t_game *game, char **heat_map, int j, int i);
void	ft_copy_door(t_door **door, t_door *new_door);

void	ft_randomize_walls(t_game *game);

void	ft_render_background(t_game *game);

void	ft_ray_cast(t_game *game);
void	ft_check_hit(t_game *game, t_ray *ray);
void	ft_track_door(t_ray	*ray, t_game *game);
int		ft_get_door_facing(t_game *game, int y, int x);

#endif
