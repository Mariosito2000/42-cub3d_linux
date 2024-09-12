/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mario.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgonza <davgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:39:38 by marias-e          #+#    #+#             */
/*   Updated: 2023/05/31 15:18:06 by davgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MARIO_H
# define MARIO_H

# include "../cub3d.h"

typedef struct s_game	t_game;
typedef struct s_ray	t_ray;

void	ft_error_exit(char *error_str, int error_code);

void	ft_check_map(t_game *game, char *file);
int		ft_check_file(char *file);
void	ft_initialize_data(t_game *game);
int		ft_check_data(t_game *game);
void	ft_manage_line(char *line, t_game *game);
void	ft_get_data(int code, char *line, t_game *game);
void	ft_process_sprite(char *info, int code, t_game *game);
void	ft_process_rgb(char *info, int code, t_game *game);

void	ft_data_error(int code);
void	ft_data_excess(int code);
void	ft_data_lack(int code);

void	ft_ray_cast(t_game *game);
void	ft_check_hit(t_game *game, t_ray *ray);

#endif
