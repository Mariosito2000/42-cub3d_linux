/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marias-e <marias-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:44:00 by davgonza          #+#    #+#             */
/*   Updated: 2023/06/12 16:39:54 by marias-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./sources_David/david.h"
# include "./sources_Mario/mario.h"

# include "../LibftMaster/ft_printf/ft_printf.h"
# include "../LibftMaster/get_next_line/get_next_line.h"
# include "../LibftMaster/libft/libft.h"
# include <math.h>
# include "../minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdio.h>

# define WIN_WIDTH		800
# define WIN_HEIGHT 	600

# define RENDER_DIST 	300
# define FOV			82

# define SPEED			0.1f
# define ANGULAR_SPEED	5

# define K_W		'w'
# define K_A		'a'
# define K_S		's'
# define K_D		'd'
# define K_UP		65362
# define K_LEFT		65361
# define K_DOWN		65364
# define K_RIGHT	65363
# define K_ESC		65307

# define NORTH_SPRITE 	1
# define SOUTH_SPRITE 	2
# define EAST_SPRITE 	3
# define WEST_SPRITE 	4
# define FLOOR_COLOR 	5
# define CEILING_COLOR 	6

# define EAST		0
# define SOUTH		90
# define WEST		180
# define NORTH		270

# define X	0
# define Y	1

# define E_W	0
# define N_S	1

# define DEG_2_RAD 0.0174532925199432957692369076848861271

typedef enum boolean {false, true}	t_bool;

typedef struct s_sprite
{
	void	*image;
	int		width;
	int		height;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	char	*buffer;
}	t_sprite;

typedef struct s_mlx
{
	void		*ptr;
	void		*win;
	t_sprite	img;
}	t_mlx;

typedef struct s_player
{
	double		pos_x;
	double		pos_y;
	double		angle;
}	t_player;

typedef struct s_inputs
{
	t_bool	w;
	t_bool	a;
	t_bool	s;
	t_bool	d;
	t_bool	left;
	t_bool	right;
}	t_inputs;

typedef struct s_visual
{
	t_sprite	north;
	t_sprite	east;
	t_sprite	south;
	t_sprite	west;
	int			floor_color;
	int			ceiling_color;
}	t_visual;

typedef struct s_map
{
	char	**chart;
	int		height;
	int		width;
}	t_map;

typedef struct s_game
{
	t_map		map;
	t_mlx		mlx;
	t_visual	visual;
	t_player	player;
	t_inputs	inputs;
}	t_game;

typedef struct s_ray
{
	int		win_x;
	double	camera_x;
	double	ray_dir[2];
	double	delta[2];
	double	map[2];
	double	step[2];
	double	side_dist[2];
	int		side;
	int		hit;
}	t_ray;

typedef struct s_column
{
	int		draw_start;
	int		draw_end;
	int		line_height;
	int		texture[2];
	double	tex_pos;
	double	step;
}	t_column;

#endif