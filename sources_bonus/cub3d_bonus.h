/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marias-e <marias-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:44:00 by davgonza          #+#    #+#             */
/*   Updated: 2023/06/21 13:07:54 by marias-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include "./sources_David/david_bonus.h"
# include "./sources_Mario/mario_bonus.h"

# include "../LibftMaster/ft_printf/ft_printf.h"
# include "../LibftMaster/get_next_line/get_next_line.h"
# include "../LibftMaster/libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/time.h>
# include <time.h>

# define WIN_WIDTH		800
# define WIN_HEIGHT 	600

# define RENDER_DIST 	300
# define FOV			90

# define SPEED			0.2f
# define ANGULAR_SPEED	6

# define MINIMAP_WALL			0x696969
# define MINIMAP_TERMINAL		0x3f7bde
# define MINIMAP_GROUND			0xDEDEDE
# define MINIMAP_VOID			0x010024
# define MINIMAP_DOOR_OPEN		0xf4c700
# define MINIMAP_DOOR_CLOSED	0xD36B50
# define MINIMAP_PLAYER			0xEF0F0F
# define MINIMAP_P_SIZE			12
# define MINIMAP_CONE			0x0FEF0F
# define MINIMAP_CONE_RANGE		30
# define MINIMAP_SIZE			200
# define MINIMAP_OFFSET_X		10
# define MINIMAP_OFFSET_Y		10
# define MINIMAP_RANGE			12

# define K_W		'w'
# define K_A		'a'
# define K_S		's'
# define K_D		'd'
# define K_UP		65362
# define K_LEFT		65361
# define K_DOWN		65364
# define K_RIGHT	65363
# define K_ESC		65307
# define K_SPACE	' '
# define K_1		'1'
# define K_2		'2'
# define K_3		'3'
# define K_4		'4'

# define EAST		0
# define SOUTH		90
# define WEST		180
# define NORTH		270

# define X	0
# define Y	1

# define E_W	0
# define N_S	1

# define DEG_2_RAD 0.0174532925199432957692369076848861271

# define CLOSE	0
# define OPEN	1

# define FLICK_RANGE		20
# define FLICK_MIN_DELAY	60

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
	t_sprite	img_post;
}	t_mlx;

typedef struct s_player
{
	double		pos_x;
	double		pos_y;
	double		angle;
	t_bool		facing_terminal;
	int			terminal_pos[2];
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
	t_sprite	wall[9];
	t_sprite	floor;
	t_sprite	ceiling[2];
	t_sprite	termemenal[11];
	int			term_frame;
	t_sprite	door_sprites[2][9];
}	t_visual;

typedef struct s_map
{
	char	**chart;
	char	**mod;
	int		height;
	int		width;
}	t_map;

typedef struct s_flick_patern
{
	int	amount;
	int	delay;
}	t_flick_patern;

typedef struct s_postpro
{
	float			***ctr_uv;
	float			**ctr_vignette;
	float			***ctr_lines;
	int				next_flick_frame_count;
	t_flick_patern	flick;
	t_bool			ctr_enabled;
	t_bool			vignette_enabled;
	t_bool			lines_enabled;
	t_bool			flick_enabled;
}	t_postpro;

typedef struct s_door
{
	int				x;
	int				y;
	int				facing;
	int				status;
	int				frame;
	struct s_door	*next;
}	t_door;

typedef struct s_terminal
{
	int					x;
	int					y;
	int					frame;
	t_door				*door;
	struct s_terminal	*next;
}	t_terminal;

typedef struct s_elements
{
	t_door		*door;
	t_terminal	*terminal;
}	t_elements;

typedef struct s_game
{
	t_map			map;
	t_mlx			mlx;
	t_visual		visual;
	t_player		player;
	t_inputs		inputs;
	t_elements		elements;
	t_postpro		post;
}	t_game;

typedef struct s_horizon
{
	int		p;
	float	pos_z;
	float	row_dist;
	double	ray_dir0[2];
	double	ray_dir1[2];
	float	step[2];
	float	floor[2];
	float	floor_step[2];
}	t_horizon;

typedef struct s_ray
{
	int				win_x;
	double			camera_x;
	double			ray_dir[2];
	double			delta[2];
	double			map[2];
	double			step[2];
	double			side_dist[2];
	int				side;
	int				hit;
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