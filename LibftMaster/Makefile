SRCS	=	ft_printf/ft_printf.c \
			ft_printf/ft_putnbr.c \
			ft_printf/ft_putnbr_base.c \
			ft_printf/ft_putptr.c \
			ft_printf/printf_utils.c \
			get_next_line/get_next_line.c \
			get_next_line/get_next_line_utils.c \
			libft/ft_atoi.c \
			libft/ft_bzero.c \
			libft/ft_calloc.c \
			libft/ft_isalnum.c \
			libft/ft_isalpha.c \
			libft/ft_isascii.c \
			libft/ft_isdigit.c \
			libft/ft_isprint.c \
			libft/ft_itoa.c \
			libft/ft_lstadd_back_bonus.c \
			libft/ft_lstadd_front_bonus.c \
			libft/ft_lstclear_bonus.c \
			libft/ft_lstdelone_bonus.c \
			libft/ft_lstiter_bonus.c \
			libft/ft_lstlast_bonus.c \
			libft/ft_lstmap_bonus.c \
			libft/ft_lstnew_bonus.c \
			libft/ft_lstsize_bonus.c \
			libft/ft_memchr.c \
			libft/ft_memcmp.c \
			libft/ft_memcpy.c \
			libft/ft_memmove.c \
			libft/ft_memset.c \
			libft/ft_putchar_fd.c \
			libft/ft_putendl_fd.c \
			libft/ft_putnbr_fd.c \
			libft/ft_putstr_fd.c \
			libft/ft_split.c \
			libft/ft_strchr.c \
			libft/ft_strdup.c \
			libft/ft_striteri.c \
			libft/ft_strjoin.c \
			libft/ft_strlcat.c \
			libft/ft_strlcpy.c \
			libft/ft_strlen.c \
			libft/ft_strmapi.c \
			libft/ft_strncmp.c \
			libft/ft_strnstr.c \
			libft/ft_strrchr.c \
			libft/ft_strtrim.c \
			libft/ft_substr.c \
			libft/ft_tolower.c \
			libft/ft_toupper.c \
			libft/ft_malloc.c \
			libft/ft_free_split.c \
			libft/ft_free.c \
			libft/ft_strjo_in.c
			

OBJS 	=	$(addprefix $(O_DIR)/, $(SRCS:.c=.o))

O_DIR	=	objs

CC	=	gcc -Wall -Wextra -Werror

NAME 	=	libft.a

$(O_DIR)/%.o: %.c
		@mkdir -p $(@D)
		@$(CC) -c $< -o $(O_DIR)/$(<:.c=.o) -I .

$(NAME):	$(OBJS)
		@ar rc $(NAME) $(OBJS)
		@printf "\033[0;32m[LIBFT COMPILED]\033[0m\n"

all:		$(NAME)

clean:
		@rm -rf $(O_DIR)

fclean:		clean
		@rm -f $(NAME)

re:		fclean all

.PHONY:	all clean fclean re