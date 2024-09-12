SRCS	=	sources/sources_David/play.c \
			sources/sources_David/image_manipulation/ft_get_img_pixel_color.c \
			sources/sources_David/image_manipulation/ft_img_pixel_put.c \
			sources/sources_David/image_manipulation/ft_spr_save_data_addr.c \
			sources/sources_David/managers/inputs_manager.c \
			sources/sources_David/managers/keys_manager.c \
			sources/sources_David/managers/player_manager.c \
			sources/sources_David/map_checker/ft_check_closed.c \
			sources/sources_David/map_checker/ft_get_map.c \
			sources/sources_David/map_checker/ft_initialize_player_position.c \
			sources/sources_David/map_checker/ft_resize_map.c \
			sources/sources_David/raycasting_render/ft_render_background.c \
			sources/sources_David/raycasting_render/ft_render_wall.c \
			sources/sources_Mario/main.c \
			sources/sources_Mario/data_checker/ft_check_data.c \
			sources/sources_Mario/data_checker/ft_check_file.c \
			sources/sources_Mario/data_checker/ft_check_map.c \
			sources/sources_Mario/data_checker/ft_data_error.c \
			sources/sources_Mario/data_checker/ft_get_data.c \
			sources/sources_Mario/data_checker/ft_initialize_data.c \
			sources/sources_Mario/data_checker/ft_manage_line.c \
			sources/sources_Mario/data_checker/ft_process_data.c \
			sources/sources_Mario/ray_caster/ft_check_ray.c \
			sources/sources_Mario/ray_caster/ft_ray_caster.c \
			sources/sources_Mario/utils/ft_error_exit.c

BONUS_SRCS	=	sources_bonus/sources_David/play_bonus.c \
				sources_bonus/sources_David/doors/ft_get_door_frame_bonus.c \
				sources_bonus/sources_David/doors/ft_get_doors_sprites_bonus.c \
				sources_bonus/sources_David/doors/ft_interact_bonus.c \
				sources_bonus/sources_David/doors/ft_is_door_open_bonus.c \
				sources_bonus/sources_David/image_manipulation/ft_get_img_pixel_color_bonus.c \
				sources_bonus/sources_David/image_manipulation/ft_img_pixel_put_bonus.c \
				sources_bonus/sources_David/image_manipulation/ft_spr_save_data_addr_bonus.c \
				sources_bonus/sources_David/managers/doors_manager_bonus.c \
				sources_bonus/sources_David/managers/inputs_manager_bonus.c \
				sources_bonus/sources_David/managers/keys_manager_bonus.c \
				sources_bonus/sources_David/managers/mouse_manager_bonus.c \
				sources_bonus/sources_David/managers/player_manager_bonus.c \
				sources_bonus/sources_David/map_checker/ft_check_closed_bonus.c \
				sources_bonus/sources_David/map_checker/ft_get_map_bonus.c \
				sources_bonus/sources_David/map_checker/ft_initialize_player_position_bonus.c \
				sources_bonus/sources_David/map_checker/ft_resize_map_bonus.c \
				sources_bonus/sources_David/minimap/minimap_bonus.c \
				sources_bonus/sources_David/postprocesing/ft_ctr_bonus.c \
				sources_bonus/sources_David/postprocesing/ft_ctr_init_bonus.c \
				sources_bonus/sources_David/postprocesing/ft_darken_color_bonus.c \
				sources_bonus/sources_David/postprocesing/ft_darken_win_bonus.c \
				sources_bonus/sources_David/postprocesing/ft_light_flickering_bonus.c \
				sources_bonus/sources_David/postprocesing/ft_swap_imgs_bonus.c \
				sources_bonus/sources_David/postprocesing/saturate_bonus.c \
				sources_bonus/sources_David/postprocesing/smoothstep_bonus.c \
				sources_bonus/sources_David/raycasting_render/ft_render_wall_bonus.c \
				sources_bonus/sources_Mario/main_bonus.c \
				sources_bonus/sources_Mario/background_render/ft_render_background_bonus.c \
				sources_bonus/sources_Mario/data_checker/ft_check_door_bonus.c \
				sources_bonus/sources_Mario/data_checker/ft_check_file_bonus.c \
				sources_bonus/sources_Mario/data_checker/ft_check_terms_bonus.c \
				sources_bonus/sources_Mario/data_checker/ft_copy_door_bonus.c \
				sources_bonus/sources_Mario/data_checker/ft_set_door_bonus.c \
				sources_bonus/sources_Mario/data_checker/ft_set_term_bonus.c \
				sources_bonus/sources_Mario/data_checker/ft_term_tracker_bonus.c \
				sources_bonus/sources_Mario/random_walls/ft_randomize_walls_bonus.c \
				sources_bonus/sources_Mario/ray_caster/ft_check_ray_bonus.c \
				sources_bonus/sources_Mario/ray_caster/ft_door_tracker_bonus.c \
				sources_bonus/sources_Mario/ray_caster/ft_get_door_facing_bonus.c \
				sources_bonus/sources_Mario/ray_caster/ft_ray_caster_bonus.c \
				sources_bonus/sources_Mario/sprite_2_img/ft_get_sprites_bonus.c \
				sources_bonus/sources_Mario/utils/ft_error_exit_bonus.c

O_DIR	=	objs

OBJS 	=	$(addprefix $(O_DIR)/, $(SRCS:.c=.o))

LIBS	=	sources/cub3d.h \
			sources/sources_David/david.h \
			sources/sources_Mario/mario.h

BONUS_O_DIR	=	bonus_objs

BONUS_OBJS 	=	$(addprefix $(BONUS_O_DIR)/, $(BONUS_SRCS:.c=.o))

BONUS_LIBS	=	sources_bonus/cub3d_bonus.h \
				sources_bonus/sources_David/david_bonus.h \
				sources_bonus/sources_Mario/mario_bonus.h

CC		=	gcc

FLAGS	=	-Wall -Wextra -Werror

NAME 	=	cub3d

BONUS_NAME	=	Duake

L_DIR	=	LibftMaster/

LIBFT	=	$(addprefix $(L_DIR), libft.a)

MLX_DIR	=	minilibx-linux/

MLX		=	$(addprefix $(MLX_DIR), libmlx.a)

MLXFLAGS =  -lmlx -lXext -lX11 -lm -lz -L ./minilibx-linux -lpthread

$(O_DIR)/%.o: %.c $(LIBS)
		@mkdir -p $(@D)
		@$(CC) $(FLAGS) -c $< -o $(O_DIR)/$(<:.c=.o)

$(BONUS_O_DIR)/%.o: %.c $(BONUS_LIBS)
		@mkdir -p $(@D)
		@$(CC) $(FLAGS) -c $< -o $(BONUS_O_DIR)/$(<:.c=.o)

all:		$(LIBFT) $(MLX) $(NAME)

bonus:		$(LIBFT) $(MLX) $(BONUS_NAME)

$(LIBFT) :
	@cd $(L_DIR) && $(MAKE) -f Makefile

$(MLX)	:
	@make -C $(MLX_DIR)

$(NAME):	$(OBJS) $(LIBFT)
	@$(CC) $(FLAGS) $(OBJS) -o $(NAME) $(LIBFT) $(MLXFLAGS)
	@printf "\033[0;32m[\e[1m$(NAME)\e[8m\033[0;32m COMPILED]\033[0m\n"

$(BONUS_NAME):	$(BONUS_OBJS)
	@$(CC) $(FLAGS) $(BONUS_OBJS) -o $(BONUS_NAME) $(LIBFT) $(MLXFLAGS)
	@printf "\033[0;32m[\e[1m$(BONUS_NAME)"\"ULTRAEXTREMEBRUTALITYEDITIONPLUS\"\(REMASTERED\)"\e[8m\033[0;32m COMPILED]\033[0m\n"

clean:
		@rm -rf $(O_DIR) $(BONUS_O_DIR) && cd $(L_DIR) && $(MAKE) clean
		@cd $(MLX_DIR) && $(MAKE) clean
		@printf "\e[0;33mobjs deleted\e[0m\n"

fclean:		clean
		@rm -f $(NAME) $(BONUS_NAME) && cd $(L_DIR) && $(MAKE) fclean
		@printf "\e[0;33mexecutables deleted\e[0m\n"

re:		fclean all

.PHONY:	all clean fclean re bonus $(LIBFT) $(MLX)
